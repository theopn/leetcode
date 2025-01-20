class Solution:
    def stringifygrid(self, grid):
        s = ""
        for i in range(2):
            for j in range(3):
                s += str(grid[i][j])
        return s

    def gridifystring(self, s):
        grid = [[-1, -1, -1], [-1, -1, -1]]
        k = 0
        for i in range(2):
            for j in range(3):
                grid[i][j] = int(s[k])
                k += 1
        return grid

    def slidingPuzzle(self, board: List[List[int]]) -> int:
        target = self.stringifygrid([[1, 2, 3], [4, 5, 0]])

        # add the current board to queue
        visited = set()
        q = deque()
        q.append((self.stringifygrid(board), 0))

        # bfs
        while q:
            s, steps = q.popleft()
            visited.add(s)

            # wow we were able to make the target grid
            if s == target:
                return steps

            # find the location of 0
            grid = self.gridifystring(s)
            zeroi = -1
            zeroj = -1
            for i in range(2):
                for j in range(3):
                    if grid[i][j] == 0:
                        zeroi, zeroj = i, j

            # 0 in top row -> try moving down
            if zeroi == 0:
                # this threw me off because even though you shallow copy the list it self (temp = grid[:]),
                # because grid is 2d array (mutable within mutable),
                # the elements in the grid (grid[0], grid[1]) are the same meaning id(grid[0]) == id(temp[0])
                # so yeah, you need to use deepcopy method
                temp = copy.deepcopy(grid)
                temp[zeroi][zeroj], temp[zeroi + 1][zeroj] = temp[zeroi + 1][zeroj], temp[zeroi][zeroj]
                temps = self.stringifygrid(temp)
                if temps not in visited:
                    #print(f"step {steps} top {s} -> {temps}")
                    q.append((temps, steps + 1))

            # 0 in bottom row -> try moving up
            if zeroi == 1:
                temp = copy.deepcopy(grid)
                temp[zeroi][zeroj], temp[zeroi - 1][zeroj] = temp[zeroi - 1][zeroj], temp[zeroi][zeroj]
                temps = self.stringifygrid(temp)
                if temps not in visited:
                    #print(f"step {steps} bot {s} -> {temps}")
                    q.append((temps, steps + 1))

            # 0 in 2nd or 3rd col -> try moving left
            if zeroj != 0:
                temp = copy.deepcopy(grid)
                temp[zeroi][zeroj], temp[zeroi][zeroj - 1] = temp[zeroi][zeroj - 1], temp[zeroi][zeroj]
                temps = self.stringifygrid(temp)
                if temps not in visited:
                    #print(f"step {steps} l {s} -> {temps}")
                    q.append((temps, steps + 1))

            # 0 in 1st or 2nd col -> try moving right
            if zeroj != 2:
                temp = copy.deepcopy(grid)
                temp[zeroi][zeroj], temp[zeroi][zeroj + 1] = temp[zeroi][zeroj + 1], temp[zeroi][zeroj]
                temps = self.stringifygrid(temp)
                if temps not in visited:
                    #print(f"step {steps} r {s} -> {temps}")
                    q.append((temps, steps + 1))


        return -1