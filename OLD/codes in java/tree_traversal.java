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

	// finding size of tree - recursive.
	public static int size_recur(node root){
		return (root==null) ? 0 : (size_recur(root.left) + 1 + size_recur(root.right));
	}

	// finding size of tree - iterative.
	public static int size_iter(node root){
		node temp = null;
		if(root == null) return 0;
		Queue<node> Q = new LinkedList<node>();
		Q.add(root);
		int size = 0;
		while(Q.size() != 0){
			temp = Q.remove();
			size++;
			if(temp.left != null){
				Q.add(temp.left);
			}
			if(temp.right != null){
				Q.add(temp.right);
			}
		}
		return size;
	} 

	// printing level order traversal in reverse order.
	public static void level_order_reverse(node root){
		node temp = null;
		Queue<node> Q = new LinkedList<node>();
		Stack<node> S = new Stack<node>();
		Q.add(root);
		while(Q.size() != 0){
			temp = Q.remove();
			if(temp.left != null) Q.add(temp.left);
			if(temp.right != null) Q.add(temp.right);
			S.push(temp);
		}
		while(S.size() != 0){
			node n = S.pop();
			System.out.println(n.data);
		}
	}

	// deleting a tree - post order traversal required.
	public static void delete_tree(node root){
		root = null;
		// if(root == null) return;
		// delete_tree(root.left);
		// root.left = null;
		// delete_tree(root.right);
		// root.right = null;
	}

	// depth of binary tree- recur
	public static int depth_recur(node root){
		if(root == null) return 0;
		int l = depth_recur(root.left);
		int r = depth_recur(root.right);
		return (l>r) ? (l+1) : (r+1);
	}

	// depth of a tree- iter : IMPORTANT
	public static int depth_iter(node root){
		if(root == null) return 0;
		node temp = null;
		Queue<node> Q = new LinkedList<node>();
		Q.add(root);
		Q.add(null);
		int depth = 1;
		while(Q.size() != 0){
			temp = Q.remove();
			if(temp == null){
				if(Q.size() != 0){
					Q.add(null);
					depth++;
				}
			}
			else{
				if(temp.left != null) Q.add(temp.left);
				if(temp.right != null) Q.add(temp.right);
			}
		}
		return depth;
	}

	// deepest node.
	public static node deepest_node(node root){
		node temp = null;
		Queue<node> Q = new LinkedList<node>();
		Q.add(root);
		while(Q.size() != 0){
			temp = Q.remove();
			if(temp.left != null) Q.add(temp.left);
			if(temp.right != null) Q.add(temp.right);
		}
		return temp;
	}

	// public static void delete_node(node root, node to_delete){
	// 	node deepest = deepest_node(root);
	// 	int temp = deepest.data;
	// 	deepest.data = to_delete.data;
	// 	to_delete.data = temp;
	// 	deepest = null; 
	// }

	// Code to find the level with maximum sum.
	public static int level_with_max_sum(node root){
		if(root == null) return 0;
		node temp = null;
		Queue<node> Q = new LinkedList<node>();
		Q.add(root);
		Q.add(null);
		int max_sum = 0;
		int sum = 0;
		while(Q.size() != 0){
			temp = Q.remove();
			if(temp == null){
				if(sum > max_sum){
					max_sum = sum;
				}
				sum = 0;
				if(Q.size() != 0) Q.add(null);
			}
			else{
				sum += temp.data;
				if(temp.left != null) Q.add(temp.left);
				if(temp.right != null) Q.add(temp.right);
			}
		}
		return max_sum;
	}

	// sum of all elements in tree.
	public static int sum_recur(node root){
		if(root == null) return 0;
		return root.data + sum_recur(root.left) + sum_recur(root.right);
	}

	public static int sum_iter(node root){
		if(root == null) return 0;
		Queue<node> Q = new LinkedList<node>();
		node temp = null;
		Q.add(root);
		int sum = 0;
		while(Q.size() != 0){
			temp = Q.remove();
			sum += temp.data;
			if(temp.left != null) Q.add(temp.left);
			if(temp.right != null) Q.add(temp.right);
		}
		return sum;
	}

	public static node mirror_image(node root){
		if(root != null){
			mirror_image(root.left);
			mirror_image(root.right);
			node temp = root.left;
			root.left = root.right;
			root.right = temp;
		}
		return root;
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
		level_order(mirror_image(root));
    }
}