import java.util.*;

class node{
	int data;
	node left, right;
	public node(int data){
		this.data = data;
		this.left = null;
		this.right = null;
	}
}

class tree_traversal{
	// iterative implementation
	public static void pre_order(node root){
		Stack<node> S = new Stack<node>();
		while(true){
			while(root != null){
				System.out.println(root.data);
				S.push(root);
				root = root.left;
			}
			if(S.size() == 0) break;
			root = S.pop();
			root = root.right;
		}
	}

	public static void in_order(node root){
		Stack<node> S = new Stack<node>();
		while(true){
			while(root != null){
				S.push(root);
				root = root.left;
			}
			if(S.size() == 0) break;
			root = S.pop();
			System.out.println(root.data);
			root = root.right; 
		}
	}

	// very important
	public static void level_order(node root){
		node temp;
		Queue<node> Q = new LinkedList<node>();
		if(root == null) return;
		Q.add(root);
		while(Q.size() != 0){
			temp = Q.remove();
			System.out.println(temp.data);
			if(temp.left != null) Q.add(temp.left);
			if(temp.right != null) Q.add(temp.right);
		}
	}

	public static int num_of_leaves(node root){
		node temp;
		Queue<node> Q = new LinkedList<node>();
		Q.add(root);
		int count=0;
		while(Q.size() != 0){
			temp = Q.remove();
			if(temp.left==null && temp.right==null) count++;
			if(temp.left != null) Q.add(temp.left);
			if(temp.right != null) Q.add(temp.right);
		}
		return count; 
	}

	public static int num_of_fullnodes(node root){
		node temp;
		Queue<node> Q = new LinkedList<node>();
		Q.add(root);
		int count=0;
		while(Q.size() != 0){
			temp = Q.remove();
			if(temp.left!=null && temp.right!=null) count++;
			if(temp.left != null) Q.add(temp.left);
			if(temp.right != null) Q.add(temp.right);
		}
		return count; 
	}

	public static int num_of_halfnodes(node root){
		node temp;
		Queue<node> Q = new LinkedList<node>();
		Q.add(root);
		int count=0;
		while(Q.size() != 0){
			temp = Q.remove();
			if(temp.left!=null^temp.right!=null) count++;
			if(temp.left != null) Q.add(temp.left);
			if(temp.right != null) Q.add(temp.right);
		}
		return count; 
	}

	// searching element in tree - recusive version.
	public static int find_recur(node root, int data){
		if(root == null) return 0;
		else{
			if(data == root.data) return 1;
			else{
				int temp = find_recur(root.left, data);
				if(temp == 1) return temp;
				else return find_recur(root.right, data);
			}
		}
	}

	// searching element in tree - iterative version.
	public static int find_iter(node root, int data){
		node temp = null;
		int result = 0;
		Queue<node> Q = new LinkedList<node>();
		Q.add(root);
		while(Q.size() != 0){
			temp = Q.remove();
			if(temp.data == data){
				result = 1;
				break;
			}
			if(temp.left != null) Q.add(temp.left);
			if(temp.right != null) Q.add(temp.right);
		}
		return result;
	}

	// inserting an element into tree.
	public static void insert(node root, int data){
		node n = new node(data);
		if(root == null){
			root = n;
			return;
		}
		node temp = null;
		Queue<node> Q = new LinkedList<node>();
		Q.add(root);
		while(Q.size() != 0){
			temp = Q.remove();
			if(temp.left != null) Q.add(temp.left);
			else{
				temp.left = n;
				return;
			}
			if(temp.right != null) Q.add(temp.right);
			else{
				temp.right = n;
			}
		} 
	}

    public static void main(String args[]) {
        node root = new node(1);
        node node2 = new node(2);
        node node3 = new node(3);
        node node4 = new node(4);
        node node5 = new node(5);
        node node6 = new node(6);
		node node7 = new node(7);
		root.left = node2;
		root.right = node3;
		node2.left = node4;
		node2.right = node5;
		node3.left = node6;
		node3.right = node7;
		insert(root, 8);
		level_order(root);
    }
}