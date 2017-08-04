#
#
import argparse
import os
import re

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

    file_contents = file_contents[:_index] + "test" + file_contents[_index:]

    print(file_contents)

    #file_contents = re.sub('\t', replacement_spaces, file_contents)

    print('Replacing tabs in {0}'.format(file_path))
    with open(file_path, "w") as f:
        f.write(file_contents)

print('Done')
