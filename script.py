import subprocess
import platform
from time import sleep
import random
import sys
import os

node_hash_power = [0, 1, 2, 3]


def run_in_new_terminal(command):
    if platform.system() == "Windows":
        subprocess.Popen(["start", "cmd", "/k", command], shell=True)
    elif platform.system() == "Linux":
        subprocess.Popen(["x-terminal-emulator", "-e", command])
    elif platform.system() == "Darwin":  # macOS
        subprocess.Popen(["open", "-a", "Terminal", command])

def start_servers():
    for i in range(4):
        command = f"python seed.py {5234+i}"
        run_in_new_terminal(command)

def generate_tree():
    command = f"python tree_generator.py {sys.argv[1]} {sys.argv[2]}"
    os.system(command)

def longest_chain():
    command = f"python longest_chain.py"
    os.system(command)



def main():
    generate_tree()
    longest_chain()

if __name__ == "__main__":
    main()
