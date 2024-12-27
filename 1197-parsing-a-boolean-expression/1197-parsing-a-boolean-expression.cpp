class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> operators;
        stack<char> operands;
        for (auto c : expression) {
            if (c == ',') {
                continue;
            } else if (c == '!' || c == '&' || c == '|') {
                operators.push(c);
            } else if (c == 't' || c == 'f' || c == '(') {
                operands.push(c);
            } else if (c == ')') {
                char lastOp = '?';
                bool seenTrue = false;
                bool seenFalse = false;
                while (operands.top() != '(') {
                    lastOp = operands.top();
                    operands.pop();
                    if (lastOp == 't') {
                        seenTrue = true;
                    } else {
                        seenFalse = true;
                    }
                }
                operands.pop(); // pop ')'

                char opt = operators.top();
                operators.pop();
                if (opt == '!') {
                    operands.push((lastOp == 't') ? 'f' : 't');
                } else if (opt == '&') {
                    operands.push((seenFalse) ? 'f' : 't');
                } else if (opt == '|') {
                    operands.push((seenTrue) ? 't' : 'f');
                }
            }
        }

        return operands.top() == 't';
    }
};