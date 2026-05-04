package bai1;

import javax.swing.*;
import java.awt.*;

public class In2P extends JFrame {

    static class Stack<S> {
        Object[] arr = new Object[1000];
        int top = -1;

        void push(S x) {
            arr[++top] = x;
        }

        @SuppressWarnings("unchecked")
        S pop() {
            return (S) arr[top--];
        }

        @SuppressWarnings("unchecked")
        S peek() {
            return (S) arr[top];
        }

        boolean empty() {
            return top == -1;
        }
    }

    public static int priority(char operator) {
        switch (operator) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            default:
                return 0;
        }
    }

    public static int result(String postfix) {
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < postfix.length(); ++i) {
            if (Character.isDigit(postfix.charAt(i))) {
                stack.push(Integer.parseInt(String.valueOf(postfix.charAt(i))));
            } else {
                if (postfix.charAt(i) == '+') {
                    int a = stack.pop();
                    int b = stack.pop();
                    stack.push(b + a);
                }
                if (postfix.charAt(i) == '*') {
                    int a = stack.pop();
                    int b = stack.pop();
                    stack.push(b * a);
                }
                if (postfix.charAt(i) == '/') {
                    int a = stack.pop();
                    int b = stack.pop();
                    if (a == 0) {
                        return -1000000000;
                    }
                    stack.push(b / a);
                }
                if (postfix.charAt(i) == '-') {
                    int a = stack.pop();
                    int b = stack.pop();
                    stack.push(b - a);
                }
                if (postfix.charAt(i) == '(' || postfix.charAt(i) == ')') {
                    return -1000000000;
                }
            }
        }
        return stack.pop();
    }

    public static String Infixtopostfix(String s) {
        Stack<Character> stack = new Stack<>();
        StringBuilder postfix = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            if (Character.isDigit(s.charAt(i))) {
                if (i < s.length() - 1 && Character.isDigit(s.charAt(i + 1))) {
                    String err = "";
                    return err;
                }
                postfix.append(s.charAt(i));
            } else if (s.charAt(i) == '(') {
                stack.push(s.charAt(i));
            } else if (s.charAt(i) == ')') {
                while (!stack.empty() && stack.peek() != '(') {
                    postfix.append(stack.pop());
                }
                stack.pop();
            } else {
                while (!stack.empty() && priority(stack.peek()) >= priority(s.charAt(i))) {
                    postfix.append(stack.pop());
                }
                stack.push(s.charAt(i));
            }
        }
        while (!stack.empty()) {
            postfix.append(stack.pop());
        }
        return postfix.toString();
    }

    public static String InfixtoPrefix(String s) {
        Stack<Character> stack = new Stack<>();
        StringBuilder prefix = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                prefix.insert(0, c);
            } else if (c == ')') {
                stack.push(c);
            } else if (c == '(') {
                while (!stack.empty() && stack.peek() != ')') {
                    prefix.insert(0, stack.pop());
                }
                stack.pop();
            } else {
                while (!stack.empty() && priority(stack.peek()) > priority(c)) {
                    prefix.insert(0, stack.pop());
                }
                stack.push(c);
            }
        }
        while (!stack.empty())
            prefix.insert(0, stack.pop());
        return prefix.toString();
    }

    JTextField textinput, textprefix, textpostfix, textresult;
    PrefixVisualizer prefixPanel;
    PostfixVisualizer postfixPanel;

    public In2P() {
        setTitle("Demo trung tố sang hậu tố và tiền tố");
        setSize(700, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JPanel topPanel = new JPanel(new GridLayout(4, 2, 10, 10));
        topPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        JLabel lableinput = new JLabel("Trung tố:");
        textinput = new JTextField();

        JLabel lableprefix = new JLabel("Tiền tố:");
        textprefix = new JTextField();
        textprefix.setEditable(false);

        JLabel lablepostfix = new JLabel("Hậu tố:");
        textpostfix = new JTextField();
        textpostfix.setEditable(false);

        JLabel lableresult = new JLabel("Kết quả:");
        textresult = new JTextField();
        textresult.setEditable(false);

        topPanel.add(lableinput);
        topPanel.add(textinput);
        topPanel.add(lableprefix);
        topPanel.add(textprefix);
        topPanel.add(lablepostfix);
        topPanel.add(textpostfix);
        topPanel.add(lableresult);
        topPanel.add(textresult);

        JPanel btnPanel = new JPanel(new FlowLayout());
        JButton Convert = new JButton("Chuyển");
        JButton Calculate = new JButton("Tính");
        JButton Clear = new JButton("Xóa");
        btnPanel.add(Convert);
        btnPanel.add(Calculate);
        btnPanel.add(Clear);

        prefixPanel = new PrefixVisualizer();
        prefixPanel.setPreferredSize(new Dimension(680, 200));
        postfixPanel = new PostfixVisualizer();
        postfixPanel.setPreferredSize(new Dimension(680, 200));

        JPanel visualPanel = new JPanel();
        visualPanel.setLayout(new GridLayout(2, 1, 0, 10));
        visualPanel.add(prefixPanel);
        visualPanel.add(postfixPanel);

        add(topPanel, BorderLayout.NORTH);
        add(btnPanel, BorderLayout.CENTER);
        add(visualPanel, BorderLayout.SOUTH);

        Convert.addActionListener(e -> {
            String s = textinput.getText().replaceAll("\\s+", "");
            String post = Infixtopostfix(s);
            String pre = InfixtoPrefix(s);
            textpostfix.setText(post);
            textprefix.setText(pre);
            prefixPanel.start(s);
            postfixPanel.start(s);
        });

        Calculate.addActionListener(e -> {
            int res = result(textpostfix.getText());
            if (res == -1000000000)
                textresult.setText("Error");
            else
                textresult.setText(String.valueOf(res));
        });

        Clear.addActionListener(e -> {
            textinput.setText("");
            textpostfix.setText("");
            textprefix.setText("");
            textresult.setText("");
            prefixPanel.clear();
            postfixPanel.clear();
        });

        setVisible(true);
    }

    class PrefixVisualizer extends JPanel implements Runnable {
        String expr;
        Stack<Character> stack = new Stack<>();
        StringBuilder output = new StringBuilder();
        int index = -1;

        public void start(String s) {
            expr = s;
            stack = new Stack<>();
            output = new StringBuilder();
            index = -1;
            new Thread(this).start();
        }

        public void clear() {
            expr = null;
            repaint();
        }

        @Override
        public void run() {
            for (int i = expr.length() - 1; i >= 0; i--) {
                index = i;
                char c = expr.charAt(i);
                repaint();
                try {
                    Thread.sleep(500);
                } catch (Exception ignored) {
                }
                if (Character.isDigit(c))
                    output.insert(0, c);
                else if (c == ')')
                    stack.push(c);
                else if (c == '(') {
                    while (!stack.empty() && stack.peek() != ')')
                        output.insert(0, stack.pop());
                    stack.pop();
                } else {
                    while (!stack.empty() && priority(stack.peek()) > priority(c))
                        output.insert(0, stack.pop());
                    stack.push(c);
                }
            }
            while (!stack.empty())
                output.insert(0, stack.pop());
            repaint();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            if (expr == null)
                return;

            Graphics2D g2 = (Graphics2D) g;
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            g2.setFont(new Font("Consolas", Font.BOLD, 16));

            g2.setColor(new Color(40, 40, 40));
            g2.drawString("Prefix Visualizer", 10, 25);

            g2.setColor(Color.BLACK);
            g2.drawString("Expr: ", 10, 60);
            for (int i = 0; i < expr.length(); i++) {
                if (i == index) {
                    g2.setColor(Color.YELLOW);
                    g2.fillRoundRect(60 + i * 25 - 3, 42, 20, 25, 5, 5);
                }
                g2.setColor(Color.BLACK);
                g2.drawString(String.valueOf(expr.charAt(i)), 60 + i * 25, 60);
            }

            g2.setColor(new Color(0, 150, 0));
            g2.drawString("Output:", 10, 100);
            g2.setColor(Color.GREEN.darker());
            g2.drawString(output.toString(), 90, 100);

            g2.setColor(Color.BLUE);
            g2.drawString("Stack:", 10, 140);
            for (int i = 0; i <= stack.top; i++) {
                g2.setColor(new Color(100, 180, 255));
                g2.fillRoundRect(70 + i * 30, 122, 25, 25, 8, 8);
                g2.setColor(Color.BLACK);
                g2.drawString(String.valueOf(stack.arr[i]), 77 + i * 30, 140);
            }

            g2.setColor(new Color(180, 180, 180));
            g2.drawRect(5, 5, getWidth() - 10, getHeight() - 10);
        }
    }

    class PostfixVisualizer extends JPanel implements Runnable {
        String expr;
        Stack<Character> stack = new Stack<>();
        StringBuilder output = new StringBuilder();
        int index = -1;

        public void start(String s) {
            expr = s;
            stack = new Stack<>();
            output = new StringBuilder();
            index = -1;
            new Thread(this).start();
        }

        public void clear() {
            expr = null;
            repaint();
        }

        @Override
        public void run() {
            for (int i = 0; i < expr.length(); i++) {
                index = i;
                char c = expr.charAt(i);
                repaint();
                try {
                    Thread.sleep(500);
                } catch (Exception ignored) {
                }
                if (Character.isDigit(c))
                    output.append(c);
                else if (c == '(')
                    stack.push(c);
                else if (c == ')') {
                    while (!stack.empty() && stack.peek() != '(')
                        output.append(stack.pop());
                    stack.pop();
                } else {
                    while (!stack.empty() && priority(stack.peek()) >= priority(c))
                        output.append(stack.pop());
                    stack.push(c);
                }
            }
            while (!stack.empty())
                output.append(stack.pop());
            repaint();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            if (expr == null)
                return;

            Graphics2D g2 = (Graphics2D) g;
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            g2.setFont(new Font("Consolas", Font.BOLD, 16));

            g2.setColor(new Color(40, 40, 40));
            g2.drawString("Postfix Visualizer", 10, 25);

            g2.setColor(Color.BLACK);
            g2.drawString("Expr: ", 10, 60);
            for (int i = 0; i < expr.length(); i++) {
                if (i == index) {
                    g2.setColor(Color.YELLOW);
                    g2.fillRoundRect(60 + i * 25 - 3, 42, 20, 25, 5, 5);
                }
                g2.setColor(Color.BLACK);
                g2.drawString(String.valueOf(expr.charAt(i)), 60 + i * 25, 60);
            }

            g2.setColor(new Color(0, 150, 0));
            g2.drawString("Output:", 10, 100);
            g2.setColor(Color.GREEN.darker());
            g2.drawString(output.toString(), 90, 100);

            g2.setColor(Color.BLUE);
            g2.drawString("Stack:", 10, 140);
            for (int i = 0; i <= stack.top; i++) {
                g2.setColor(new Color(100, 180, 255));
                g2.fillRoundRect(70 + i * 30, 122, 25, 25, 8, 8);
                g2.setColor(Color.BLACK);
                g2.drawString(String.valueOf(stack.arr[i]), 77 + i * 30, 140);
            }

            g2.setColor(new Color(180, 180, 180));
            g2.drawRect(5, 5, getWidth() - 10, getHeight() - 10);
        }
    }

    public static void main(String[] args) {
        new In2P();
    }
}
