# Phân loại cây

- N-ary tree: 1 cây gồm 0-n node, được gọi là cây tổng quát
- Ternary tree: số node con của 1 node không quá 3 node, được gọi là cây tam phân
- Binary tree: số node con của 1 node không quá 2 node, được sử dụng nhiều nhất, được gọi là cây nhị phân

=> chúng ta chỉ tập trung tìm hiểu và làm việc với Binary tree

## Dựa vào tính chất của cây

- Cây nhị phân suy biến: là cây chỉ có node con chỉ nằm bên trái hoặc bên phải => chiều cao cây h = số node - 1
- Cây nhị phân đầy đủ: ở mỗi node có đầy đủ 2 node con, tổng số node ở độ cao h = 2^(h+1) - 1 và số node ở độ cao h = 2^h
- Cây nhị phân gần hoàn chỉnh: cây khi bỏ hết hàng cuối thì được "cây nhị phân đầy đủ"
- Cây nhị phân tìm kiếm: tất cả node con bên trái nhỏ hơn node 'root' và node con bên phải đều lớn hơn node 'root' (Binary Search Tree - BST)

## Thao tác với BST

### Thêm node vào cây

\*_Gọi node được add = addNode_

- TH1: Nếu root = null => gán giá trị của root = addNode
- TH2: Nếu root != null
  So sánh addNode với root, sau đấy so sánh với các child node: left & right
  => nhỏ hơn thì nhảy sang trái, lớn hơn thì nhảy sang phải
  => đến khi nào gặp node null => gán giá trị = addNode
  \*Có 2 cách để thêm 1 node vào BST: dùng vòng lặp hoặc dùng đệ quy

### Xóa node trên cây

\*Xác đinh node cần xóa, gọi là: removeNode

- TH1: removeNode không có node con (node lá)
  Tìm node cha của nó và trỏ node cha vào NULL
- TH2: removeNode có 1 node con
  Xác định node cha của removeNode, trỏ node cha vào node con của removeNode
- TH3: removeNode có 2 node con
  Method 1: thay bởi node trái cùng của cây con bên phải => pp này mục đích tìm được giá trị nào nhỏ hơn các node bên phải (của node bị xóa) và lớn hơn các node bên trái.
  Method 2: thay bởi node phải cùng của cây con bên trái

### Tìm node trên cây

- Thực hiện tìm node như cách tìm 1 node để tiến hành xóa.

### Duyệt cây

\*Có 3 cách duyệt cây

- 1: Pre-order Traversal: Node -> L -> R
- 2: In-order Traversal: L -> Node -> R
- 3: Post-order Traversal: L -> R -> Node
