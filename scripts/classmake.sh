#Hello
#!/bin/bash
if [ -z $1 ] || [ -z $2 ] || [ -z $3 ]; then
    echo "newclass requires 3 arguments: newclass PROJECT NAMESPACE CLASS"

elif [ -e $3.h ] || [ -e $3.cpp ]; then
  echo "Source files for $3 already exists!"

else
    #parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
    #cd "$parent_path"

    #Prep substitution values
    projectName=$1
    namespace=$2
    className=$3
    
    #Calculate all-caps for precompiler symbols
    projectName_Upper=$(echo "$1" | tr '[:lower:]' '[:upper:]')
    namespace_Upper=$(echo "$2" | tr '[:lower:]' '[:upper:]')
    className_Upper=$(echo "$3" | tr '[:lower:]' '[:upper:]')

    #   Generate The Header
    #Copy template header to buffer
    headerTemplateData=`cat newclass_sourcetemplates/headertemplate`

    #Apply symbols to buffer
    headerTemplateData="${headerTemplateData//\$\{PROJECTNAMEUPPER\}/$projectName_Upper}"
    headerTemplateData="${headerTemplateData//\$\{NAMESPACEUPPER\}/$namespace_Upper}"
    headerTemplateData="${headerTemplateData//\$\{CLASSNAMEUPPER\}/$className_Upper}"

    headerTemplateData="${headerTemplateData//\$\{PROJECTNAME\}/$projectName}"
    headerTemplateData="${headerTemplateData//\$\{NAMESPACE\}/$namespace}"
    headerTemplateData="${headerTemplateData//\$\{CLASSNAME\}/$className}"
    
    headerTemplateData="${headerTemplateData//\$\{YEAR\}/$(date +%Y)}"
    headerTemplateData="${headerTemplateData//\$\{DATE\}/$(date +"%y-%m-%d")}"
    #headerTemplateData="${headerTemplateData//\$\{TIME\}/$(date +%T)}"

    echo "$parent_path$headerTemplateData" >> $className.h

    #   Generate The CPP
    #Copy template cpp to buffer
    cppTemplateData=`cat newclass_sourcetemplates/cpptemplate`

    #Apply symbols to buffer
    cppTemplateData="${cppTemplateData//\$\{PROJECTNAMEUPPER\}/$projectName_Upper}"
    cppTemplateData="${cppTemplateData//\$\{NAMESPACEUPPER\}/$namespace_Upper}"
    cppTemplateData="${cppTemplateData//\$\{CLASSNAMEUPPER\}/$className_Upper}"

    cppTemplateData="${cppTemplateData//\$\{PROJECTNAME\}/$projectName}"
    cppTemplateData="${cppTemplateData//\$\{NAMESPACE\}/$namespace}"
    cppTemplateData="${cppTemplateData//\$\{CLASSNAME\}/$className}"

    cppTemplateData="${cppTemplateData//\$\{YEAR\}/$(date +%Y)}"
    cppTemplateData="${cppTemplateData//\$\{DATE\}/$(date +"%y-%m-%d")}"
    
    echo "$cppTemplateData" >> $PWD/$className.cpp

fi