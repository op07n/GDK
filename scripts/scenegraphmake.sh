#Hello
#!/bin/bash
if [ -z $1 ] || [ -z $2 ]; then
    echo "newcomponent requires 2 arguments: newcomponent NAMESPACE SCENEGRAPHNAME"

elif [ -e $2.h ] || [ -e $2.cpp ]; then
  echo "Source files for $2 already exists!"

else
    #parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
    #cd "$parent_path"

    #Prep substitution values
    namespace=$1
    className=$2
    
    #Calculate all-caps for precompiler symbols
    namespace_Upper=$(echo "$1" | tr '[:lower:]' '[:upper:]')
    className_Upper=$(echo "$2" | tr '[:lower:]' '[:upper:]')

    #   Generate The Header
    #Copy template header to buffer
    headerTemplateData=`cat newscenegraph_templates/headertemplate`

    #Apply symbols to buffer
    headerTemplateData="${headerTemplateData//\$\{NAMESPACEUPPER\}/$namespace_Upper}"
    headerTemplateData="${headerTemplateData//\$\{CLASSNAMEUPPER\}/$className_Upper}"

    headerTemplateData="${headerTemplateData//\$\{NAMESPACE\}/$namespace}"
    headerTemplateData="${headerTemplateData//\$\{CLASSNAME\}/$className}"
    
    headerTemplateData="${headerTemplateData//\$\{YEAR\}/$(date +%Y)}"
    headerTemplateData="${headerTemplateData//\$\{DATE\}/$(date +"%y-%m-%d")}"
    #headerTemplateData="${headerTemplateData//\$\{TIME\}/$(date +%T)}"

    echo "$parent_path$headerTemplateData" >> $className.h

    #   Generate The CPP
    #Copy template cpp to buffer
    cppTemplateData=`cat newscenegraph_templates/cpptemplate`

    #Apply symbols to buffer
    cppTemplateData="${cppTemplateData//\$\{NAMESPACEUPPER\}/$namespace_Upper}"
    cppTemplateData="${cppTemplateData//\$\{CLASSNAMEUPPER\}/$className_Upper}"

    cppTemplateData="${cppTemplateData//\$\{NAMESPACE\}/$namespace}"
    cppTemplateData="${cppTemplateData//\$\{CLASSNAME\}/$className}"

    cppTemplateData="${cppTemplateData//\$\{YEAR\}/$(date +%Y)}"
    cppTemplateData="${cppTemplateData//\$\{DATE\}/$(date +"%y-%m-%d")}"
    
    echo "$cppTemplateData" >> $PWD/$className.cpp

fi