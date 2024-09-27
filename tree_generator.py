import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import tkinter as tk
from tkinter import ttk

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
def visualize_chain(chain, root):
    fig, ax = plt.subplots(figsize=(10, 200))  # Adjust figure size for more vertical space

    # Create a hierarchical layout and scale the vertical positions
    pos = nx.nx_agraph.graphviz_layout(chain, prog='dot')
    for node, (x, y) in pos.items():
        pos[node] = (x, y * 2)  # Scale the y-coordinate for more vertical space

    # Draw the graph
    nx.draw(chain, pos, ax=ax, with_labels=True, node_shape='o', node_color='lightblue', 
            node_size=2000, font_size=10, arrows=True)
    
    # Save the figure
    fig.savefig('chain_graph.png')  # Save the figure to a file

    # Embed the plot in Tkinter canvas
    canvas = FigureCanvasTkAgg(fig, master=root)
    canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=1)
    canvas.draw()

# Add scrollable functionality to the window
def make_scrollable_window():
    root = tk.Tk()
    root.title("Scrollable Chain Graph")
    
    # Create a frame to hold the canvas and scrollbar
    main_frame = ttk.Frame(root)
    main_frame.pack(fill=tk.BOTH, expand=1)

    # Create a canvas for scrolling
    my_canvas = tk.Canvas(main_frame)
    my_canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=1)

    # Add a scrollbar to the canvas
    scrollbar = ttk.Scrollbar(main_frame, orient=tk.VERTICAL, command=my_canvas.yview)
    scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

    # Configure the canvas
    my_canvas.configure(yscrollcommand=scrollbar.set)
    my_canvas.bind('<Configure>', lambda e: my_canvas.configure(scrollregion=my_canvas.bbox("all")))

    # Create another frame inside the canvas to hold the plot
    second_frame = ttk.Frame(my_canvas)
    my_canvas.create_window((0, 0), window=second_frame, anchor="nw")

    return root, second_frame

# Main execution
def main(csv_file_path):
    df = load_csv(csv_file_path)
    chain = build_chain(df)
    
    # Create a scrollable window and embed the graph in it
    root, second_frame = make_scrollable_window()
    visualize_chain(chain, second_frame)
    root.mainloop()

# Path to the CSV file
csv_file_path = 'block_data0.csv'

main(csv_file_path)
