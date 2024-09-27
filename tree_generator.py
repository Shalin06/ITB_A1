import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt

# Load CSV data
def load_csv(file_path):
    df = pd.read_csv(file_path)
    return df

# Build the chain graph from the child-parent relationships
def build_chain(df):
    chain = nx.DiGraph()  # Directed graph for the chain
    for _, row in df.iterrows():
        child, parent = row[0], row[1]
        chain.add_edge(parent, child)  # Add edge from parent to child
    return chain

# Plot using matplotlib for more control over layout
def visualize_chain(chain):
    pos = nx.nx_agraph.graphviz_layout(chain, prog='dot')  # Create a hierarchical layout
    plt.figure(figsize=(10, 20))  # Adjust figure size for a long vertical structure
    nx.draw(chain, pos, with_labels=True, node_shape='o', node_color='lightblue', node_size=2000, font_size=10, arrows=True)
    plt.show()

# Main execution
def main(csv_file_path):
    df = load_csv(csv_file_path)
    chain = build_chain(df)
    visualize_chain(chain)

# Path to the CSV file
csv_file_path = 'data.csv'

main(csv_file_path)
