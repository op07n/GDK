# Platform: OSX
# Name: Alphabetize
# Function: expects \n separated value string in system clipboard, 
# reorganizes alphabetically and overwrites output to clipboard
#
import subprocess

def read_from_clipboard():
    return subprocess.check_output('pbpaste', env={'LANG': 'en_US.UTF-8'}).decode('utf-8')
        
def write_to_clipboard(output):
    process = subprocess.Popen('pbcopy', env={'LANG': 'en_US.UTF-8'}, stdin=subprocess.PIPE)
    process.communicate(output.encode('utf-8'))

_Input = read_from_clipboard()

_List = _Input.split('\n')
_List.sort()

_Output = "\n".join(str(x) for x in _List)

write_to_clipboard(_Output)