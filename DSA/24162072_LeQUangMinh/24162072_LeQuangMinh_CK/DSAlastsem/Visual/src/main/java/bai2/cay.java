package bai2;

import java.util.ArrayList;
import javax.swing.*;
import javax.swing.tree.*;
import java.awt.*;
import java.awt.event.*;

public class cay {
    static class Node {
        private String data;

        public Node(String s) {
            data = s;
        }

        public Node(Node root) {
            data = root.data;
        }

        public String getData() {
            return data;
        }

        public void setData(String s) {
            data = s;
        }
    }

    static class TreeNode {
        private Node node;
        private TreeNode parent;
        private ArrayList<TreeNode> child;

        public TreeNode(Node root) {
            node = new Node(root);
            parent = null;
            child = new ArrayList<TreeNode>();
        }
    }

    public static void addChildatNode(TreeNode p, TreeNode childNode) {
        childNode.parent = p;
        p.child.add(childNode);
    }

    public static void removeNode(TreeNode p, String name) {
        for (int i = 0; i < p.child.size(); i++) {
            TreeNode v = p.child.get(i);
            if (v.node.getData().equals(name)) {
                p.child.remove(i);
                return;
            }
            removeNode(v, name);
        }
    }

    public static TreeNode findNode(TreeNode t, String name) {
        if (t == null)
            return null;
        if (t.node.getData().equals(name))
            return t;
        for (TreeNode v : t.child) {
            TreeNode f = findNode(v, name);
            if (f != null)
                return f;
        }
        return null;
    }

    public static int getDepth(TreeNode t) {
        if (t == null)
            return 0;
        if (t.child.size() == 0)
            return 1;
        int max = 0;
        for (TreeNode v : t.child) {
            int d = getDepth(v);
            if (d > max)
                max = d;
        }
        return max + 1;
    }

    public static void getNodesAtLevel(TreeNode t, int level, int cur, ArrayList<String> res) {
        if (t == null)
            return;
        if (cur == level)
            res.add(t.node.getData());
        for (TreeNode v : t.child)
            getNodesAtLevel(v, level, cur + 1, res);
    }

    public static void getChildCount(TreeNode t, ArrayList<String> res) {
        if (t == null)
            return;
        res.add(t.node.getData() + ": " + t.child.size());
        for (TreeNode v : t.child)
            getChildCount(v, res);
    }

    public static DefaultMutableTreeNode buildSwingTree(TreeNode t) {
        if (t == null || t.node == null)
            return null;
        DefaultMutableTreeNode swingNode = new DefaultMutableTreeNode(t.node.getData());
        for (TreeNode v : t.child) {
            DefaultMutableTreeNode sub = buildSwingTree(v);
            if (sub != null)
                swingNode.add(sub);
        }
        return swingNode;
    }

    public static void reloadTree(JTree tree, TreeNode root) {
        DefaultMutableTreeNode swingRoot = buildSwingTree(root);
        tree.setModel(new DefaultTreeModel(swingRoot));
    }

    public static void main(String args[]) {
        Node root = new Node("Ông A");
        TreeNode a = new TreeNode(root);
        TreeNode b = new TreeNode(new Node(new Node("Bố B1")));
        TreeNode c = new TreeNode(new Node(new Node("Mẹ B2")));
        TreeNode d = new TreeNode(new Node(new Node("Cháu Bố B1")));
        TreeNode e = new TreeNode(new Node(new Node("Em trai Bố B1")));
        TreeNode f = new TreeNode(new Node(new Node("Cháu Mẹ B2")));

        addChildatNode(a, b);
        addChildatNode(a, c);
        addChildatNode(b, d);
        addChildatNode(b, e);
        addChildatNode(c, f);

        JFrame f1 = new JFrame("Demo Cây gia phả");
        f1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f1.setSize(500, 400);
        f1.setLayout(new BorderLayout());

        DefaultMutableTreeNode swingRoot = buildSwingTree(a);
        JTree tree = new JTree(swingRoot);
        JScrollPane scroll = new JScrollPane(tree);
        f1.add(scroll, BorderLayout.CENTER);

        JPanel panel = new JPanel();
        JTextField input = new JTextField(10);
        JButton add = new JButton("Thêm");
        JButton delete = new JButton("Xóa");
        JButton rename = new JButton("Chỉnh sửa");
        JButton depth = new JButton("Tổng số thế hệ");
        JButton same = new JButton("Số thành viên trong 1 thế hệ");
        JButton child = new JButton("Số con cháu của 1 nút");

        panel.add(input);
        panel.add(add);
        panel.add(delete);
        panel.add(rename);
        panel.add(depth);
        panel.add(same);
        panel.add(child);

        JScrollPane scrollPanel = new JScrollPane(panel);
        scrollPanel.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        scrollPanel.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_NEVER);
        f1.add(scrollPanel, BorderLayout.SOUTH);

        add.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e1) {
                String val = input.getText().trim();
                if (val.isEmpty())
                    return;
                DefaultMutableTreeNode selected = (DefaultMutableTreeNode) tree.getLastSelectedPathComponent();
                String selectedName = selected == null ? a.node.getData() : selected.toString();
                TreeNode par = findNode(a, selectedName);
                if (par != null) {
                    TreeNode newNode = new TreeNode(new Node(new Node(val)));
                    addChildatNode(par, newNode);
                    reloadTree(tree, a);
                }
                input.setText("");
            }
        });

        delete.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e2) {
                DefaultMutableTreeNode selected = (DefaultMutableTreeNode) tree.getLastSelectedPathComponent();
                if (selected == null)
                    return;
                String name = selected.toString();
                if (name.equals(a.node.getData()))
                    return;
                removeNode(a, name);
                reloadTree(tree, a);
            }
        });

        rename.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e6) {
                DefaultMutableTreeNode selected = (DefaultMutableTreeNode) tree.getLastSelectedPathComponent();
                if (selected == null)
                    return;
                String old = selected.toString();
                String val = input.getText().trim();
                if (val.isEmpty())
                    return;
                TreeNode target = findNode(a, old);
                if (target != null)
                    target.node.setData(val);
                reloadTree(tree, a);
                input.setText("");
            }
        });

        depth.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e3) {
                int depth = getDepth(a);
                JOptionPane.showMessageDialog(f1, "Số thế hệ: " + depth);
            }
        });

        same.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e4) {
                String lvl = JOptionPane.showInputDialog(f1, "Nhập thế hệ cần in theo số:");
                try {
                    int l = Integer.parseInt(lvl);
                    ArrayList<String> res = new ArrayList<String>();
                    getNodesAtLevel(a, l, 1, res);
                    JOptionPane.showMessageDialog(f1, "Các thế hệ tại " + l + ": " + res);
                } catch (Exception ex) {
                }
            }
        });

        child.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e5) {
                ArrayList<String> res = new ArrayList<String>();
                getChildCount(a, res);
                JOptionPane.showMessageDialog(f1, String.join("\n", res));
            }
        });

        f1.setVisible(true);
    }
}
