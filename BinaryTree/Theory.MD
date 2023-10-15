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