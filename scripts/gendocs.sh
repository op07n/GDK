echo -- echo generating docs...
echo -- requires doxygen to be installed in your system
cd ../docs/
doxygen doxyconf.txt
echo -- gendocs.sh complete
echo -- check output at root/docs/html/
