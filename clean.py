import os
def clean():
    # Get a list of all files in the current directory
    files = os.listdir('.')
    
    # Delete all .txt files
    for file in files:
        if file.endswith('.txt'):
            os.remove(file)
    
    # Delete all .csv files except for result.csv
    for file in files:
        if file.endswith('.csv') and file not in ['result.csv', 'result_new.csv']:
            os.remove(file)

clean()