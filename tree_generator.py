import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt
import sys
import os

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

# Plot using matplotlib for more control over layout and save the image
def visualize_chain(chain):
    fig, ax = plt.subplots(figsize=(20, 500))  # Adjust figure size for more vertical space

    # Create a hierarchical layout and scale the vertical positions
    pos = nx.nx_agraph.graphviz_layout(chain, prog='dot')
    for node, (x, y) in pos.items():
        pos[node] = (x*10, (y-1)*100)  # Scale the y-coordinate for more vertical space

    # Draw the graph
    nx.draw(chain, pos, ax=ax, with_labels=True, node_shape='o', node_color='lightblue', 
            node_size=500, font_size=8, arrows=True)
    
    # Save the figure
    if os.path.exists('result_trees_2') == False:
        os.mkdir('result_trees_2')
    fig.savefig(f'result_trees_2/graph_{sys.argv[1]}_{sys.argv[2]}.png')  # Save the figure to a file

# Main execution
def main(csv_file_path):
    df = load_csv(csv_file_path)
    chain = build_chain(df)
    
    # Create a scrollable window and embed the graph in it
    # root, second_frame = make_scrollable_window()
    visualize_chain(chain)
    # root.mainloop()

# Path to the CSV file
csv_file_path = 'block_data0.csv'

main(csv_file_path)
