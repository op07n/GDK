#
#
import argparse
import os
import re

def handleHeader(_aFileContents):
    "This function injects namespace braces into a header file, open under the last #include, close above the last #endif"
    _Includes = [(m.start(0), m.end(0)) for m in re.finditer("#include", _aFileContents)]
    _IndexOfLastIncludeEnd = _Includes[len(_Includes)-1][1]
    _IndexOfLastIncludeEndOfLine = [pos for pos, char in enumerate(_aFileContents[_IndexOfLastIncludeEnd:]) if char == '\n'][0] + _IndexOfLastIncludeEnd

    #insert 'namespace GDK{namespace Physics2D{\n'
    _aFileContents = _aFileContents[:_IndexOfLastIncludeEndOfLine] + '\nnamespace GDK{namespace Physics2D{\n' + _aFileContents[_IndexOfLastIncludeEndOfLine:]

    #get index of the beginning of the last '#endif*'
    _EndIfs = [(m.start(0), m.end(0)) for m in re.finditer("#endif", _aFileContents)]
    _IndexOfLastEndIf = _EndIfs[len(_EndIfs)-1][0]

    #insert '}}\n'
    _aFileContents = _aFileContents[:_IndexOfLastEndIf] + '\n}}\n' + _aFileContents[_IndexOfLastEndIf:]

    print (_IndexOfLastIncludeEndOfLine)
    print(_aFileContents)

    return _aFileContents

def handleCPP(_aFileContents):
    "This function injects a using namespace statement under the last #include line"
    _Includes = [(m.start(0), m.end(0)) for m in re.finditer("#include", _aFileContents)]
    _IndexOfLastIncludeEnd = _Includes[len(_Includes)-1][1]
    _IndexOfLastIncludeEndOfLine = [pos for pos, char in enumerate(_aFileContents[_IndexOfLastIncludeEnd:]) if char == '\n'][0] + _IndexOfLastIncludeEnd

    #insert 'namespace GDK{namespace Physics2D{\n'
    _aFileContents = _aFileContents[:_IndexOfLastIncludeEndOfLine] + '\nusing GDK::Physics2D;\n' + _aFileContents[_IndexOfLastIncludeEndOfLine:]

    #get index of the beginning of the last '#endif*'
    _EndIfs = [(m.start(0), m.end(0)) for m in re.finditer("#endif", _aFileContents)]
    _IndexOfLastEndIf = _EndIfs[len(_EndIfs)-1][0]

    #insert '}}\n'
    _aFileContents = _aFileContents[:_IndexOfLastEndIf] + '\n}}\n' + _aFileContents[_IndexOfLastEndIf:]

    print(_aFileContents)

    return 

parser = argparse.ArgumentParser(description='Envelop .h and .cpp files with the namespace.')
parser.add_argument('root_directory',  type=str, default='./test',  nargs='?', help='directory to run the script in')
parser.add_argument('spaces_for_tab',  type=int, default=4,    nargs='?', help='number of spaces for one tab'  )
parser.add_argument('file_mask_regex', type=str, default=".*", nargs='?', help='file name mask regex'          )

args = parser.parse_args()
file_mask_regex = re.compile(args.file_mask_regex)
replacement_spaces = ' ' * args.spaces_for_tab

print('Starting tab replacement. directory {0}, spaces number {1}, file mask {2}'.format(args.root_directory, args.spaces_for_tab, args.file_mask_regex))

found_files = []
for path, subdirs, files in os.walk(args.root_directory):
    for name in files:
        found_files.append(os.path.join(path, name))

matched_files = [name for name in found_files if file_mask_regex.match(name)]

for file_path in matched_files:
    file_contents = ''
    with open(file_path) as f:
        file_contents = f.read()

    _index = 0
    for result in re.finditer("#define", file_contents):
        print result

    print(handleHeader(file_contents))
    print(handleCPP(file_contents))


    print('Replacing tabs in {0}'.format(file_path))
    with open(file_path, "w") as f:
        f.write(file_contents)

print('Done')
