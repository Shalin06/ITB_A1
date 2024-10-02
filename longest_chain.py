import csv
from collections import defaultdict

# Step 1: Read the CSV file and parse the data
def read_csv(file_path):
    data = []
    flag = 1
    with open(file_path, mode='r') as file:
        csv_reader = csv.reader(file)
        for row in csv_reader:
            if flag:
                flag = 0
                continue
            child, parent, timestamp, generator = row
            data.append((child, parent, int(timestamp), int(generator)))
    return data

# Step 2: Build parent-child relationship and generator map
def build_tree_and_generators(data):
    tree = defaultdict(list)  # Store children for each parent
    parent_map = {}           # Track each block's parent
    generators = {}           # Store the generator for each block

    for child, parent, timestamp, generator in data:
        tree[parent].append((child, timestamp))
        parent_map[child] = parent
        generators[child] = generator

    # Identify the root (block that has no parent in the dataset)
    all_blocks = set(parent_map.keys()).union(set(tree.keys()))
    root_candidates = all_blocks.difference(set(parent_map.keys()))

    root = list(root_candidates)[0]  # Assume there's only one root
    return tree, generators, parent_map, root

# Step 3: DFS to find the longest chain
def dfs(node, tree):
    if node not in tree:
        return [node]  # Leaf node
    max_chain = []
    for child, timestamp in sorted(tree[node], key=lambda x: x[1]):
        chain = dfs(child, tree)
        if len(chain) > len(max_chain):
            max_chain = chain
    return [node] + max_chain

# Step 4: Backtrack from any leaf to the root to find the longest chain
def find_longest_chain(parent_map, root):
    # Find all leaf nodes (nodes that are not parents)
    leaves = set(parent_map.keys()) - set(parent_map.values())
    
    longest_chain = []
    for leaf in leaves:
        chain = []
        current_node = leaf
        while current_node in parent_map or current_node == root:
            chain.append(current_node)
            if current_node == root:
                break
            current_node = parent_map[current_node]
        if len(chain) > len(longest_chain):
            longest_chain = chain

    return longest_chain[::-1]  # Reverse to get root to leaf order

# Step 5: Count generator block fractions in the longest chain
def count_generator_fractions(longest_chain, generators):
    generator_count = defaultdict(int)
    for block in longest_chain:
        generator_count[generators.get(block, 0)] += 1

    total_blocks = len(longest_chain)
    generator_fraction = {gen: count / total_blocks for gen, count in generator_count.items()}
    return generator_fraction

# Main function to process the CSV and find the longest chain and generator fractions
def main(file_path):
    # Read and parse the CSV file
    data = read_csv(file_path)
    
    # Build the tree and find the root
    tree, generators, parent_map, root = build_tree_and_generators(data)

    # Find the longest chain
    longest_chain = find_longest_chain(parent_map, root)

    # Count the fraction of blocks for each generator in the longest chain
    generator_fractions = count_generator_fractions(longest_chain, generators)

    with open('result_new.csv', mode='a') as file:
        ans = 0
        if 39 in generator_fractions:
            ans = generator_fractions[39]
        file.write(f"{ans}\n")
    # Print the results
    print("Longest Chain:", len(longest_chain))
    print("Generator Block Fractions in Longest Chain:", generator_fractions)
    print(sum(generator_fractions.values()))

# Example usage
file_path = "block_data0.csv"  # Replace this with the path to your CSV file
main(file_path)
