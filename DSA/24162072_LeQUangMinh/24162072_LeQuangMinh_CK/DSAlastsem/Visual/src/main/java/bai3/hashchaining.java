package bai3;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

public class hashchaining extends JFrame {
    static class Hash {
        private final int m;
        private final List<LinkedList<Integer>> buckets;

        public Hash(int m) {
            this.m = m;
            this.buckets = new ArrayList<>(m);
            for (int i = 0; i < m; ++i) {
                buckets.add(new LinkedList<>());
            }
        }

        int getindex(int key) {
            return (key % m + m) % m;
        }

        public void put(int key) {
            int idx = getindex(key);
            LinkedList<Integer> chain = buckets.get(idx);
            for (int v : chain) {
                if (v == key)
                    return;
            }
            chain.addFirst(key);
        }

        public int Search(int key) {
            int idx = getindex(key);
            LinkedList<Integer> chain = buckets.get(idx);
            int res = 1;
            for (int c : chain) {
                if (c == key)
                    break;
                res += 1;
            }
            return res;
        }

        public void printTable(JTextArea out) {
            out.append("Hash Table Chaining\n");
            int counter = 0;
            for (var c : buckets) {
                out.append(String.format("Bucket[%d] = [", counter));
                for (int v : c) {
                    out.append(String.format("%d -> ", v));
                }
                out.append("null");
                out.append("]\n");
                counter += 1;
            }
        }
    }

    public static int LinearSearch(ArrayList<Integer> a, int x) {
        int res = 1;
        for (int c : a) {
            if (c == x)
                return res;
            res += 1;
        }
        return res;
    }

    private final JTextArea log;
    private final JTextArea out;
    private final JButton runbutton;
    private final JButton addbutton;
    private final JTextField addField;

    private int m = 31;
    private int n = 100;
    private int q = 50;
    private ArrayList<Integer> test;
    private Hash Table;

    public hashchaining() {
        super("Demo thuật toán hash");

        log = new JTextArea();
        log.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 15));
        log.setEditable(false);

        out = new JTextArea();
        out.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 15));
        out.setEditable(false);

        runbutton = new JButton("Sinh mảng");
        runbutton.addActionListener(e -> algorthm());

        addbutton = new JButton("Thêm số");
        addField = new JTextField(10);
        addbutton.addActionListener(e -> addNumber());

        setLayout(new BorderLayout(8, 8));

        JPanel top = new JPanel(new BorderLayout());
        top.setBorder(BorderFactory.createTitledBorder("Mảng"));
        top.add(new JScrollPane(log), BorderLayout.CENTER);

        JPanel control = new JPanel();
        control.add(runbutton);
        control.add(new JLabel("Thêm số:"));
        control.add(addField);
        control.add(addbutton);

        JPanel center = new JPanel(new BorderLayout());
        center.setBorder(BorderFactory.createTitledBorder("Hash Table"));
        center.add(new JScrollPane(out), BorderLayout.CENTER);

        add(top, BorderLayout.NORTH);
        add(center, BorderLayout.CENTER);
        add(control, BorderLayout.SOUTH);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(900, 700);
        setLocationRelativeTo(null);
        setVisible(true);

        algorthm();
    }

    private void algorthm() {
        Random rng = new Random();
        test = new ArrayList<>(n);
        for (int i = 0; i < n; ++i) {
            test.add(rng.nextInt(1234));
        }
        Table = new Hash(m);
        for (int c : test) {
            Table.put(c);
        }
        updateDisplay();
    }

    private void addNumber() {
        try {
            int x = Integer.parseInt(addField.getText().trim());
            test.add(x);
            Table.put(x);
            updateDisplay();
            addField.setText("");
        } catch (Exception ignored) {
        }
    }

    private void updateDisplay() {
        log.setText("");
        for (int i = 0; i < test.size(); ++i) {
            log.append(String.format("%4d", test.get(i)));
            if ((i + 1) % 10 == 0 || i == test.size() - 1)
                log.append("\n");
        }
        out.setText("");
        Table.printTable(out);
        Random rng = new Random();
        int totalLinear = 0;
        int totalHash = 0;
        int Q = q;
        while (Q-- > 0) {
            int idx = rng.nextInt(test.size());
            int x = test.get(idx);
            totalLinear += LinearSearch(test, x);
            totalHash += Table.Search(x);
        }
        out.append(String.format("\nLinearSearchAvg: %d / %d = %.2f", totalLinear, q, (totalLinear * 1.00) / q));
        out.append("\n");
        out.append(String.format("HashSearchAvg: %d / %d = %.2f", totalHash, q, (totalHash * 1.00) / q));
    }

    public static void main(String args[]) {
        SwingUtilities.invokeLater(() -> new hashchaining());
    }
}
