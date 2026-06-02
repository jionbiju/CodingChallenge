package Stack;


import java.util.Stack;

public class BalancedParentheses {

    boolean isValid(String exp){
        Stack<Character> stack = new Stack<>();
        for (char ch: exp.toCharArray()){
            if (ch == '{' || ch == '[' || ch == '('){
                stack.push(ch);
            } else if (ch == '}' || ch == ']' || ch == ')') {
                if (stack.isEmpty()){
                    return false;
                }
                char curr = stack.pop();
                if (curr == '{' && ch !='}' ||
                    curr == '[' && ch != ']' || curr == '{' && ch != '}'){
                    return false;
                }
            }
        }
        if (stack.isEmpty()){
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        BalancedParentheses bp = new BalancedParentheses();
        System.out.println("Is valid parentheses:"+bp.isValid("{}[]()}"));
    }
}

/*
OUTPUT
Is valid parentheses:false
 */