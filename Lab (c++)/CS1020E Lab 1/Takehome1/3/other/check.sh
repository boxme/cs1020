if [ "$1" == "Java" ]; then
	########### script for Java ########### 
	for i in *.java; do
		file=$i
	done
	#only alows 1 file.
	name=`basename $file | sed 's/\(.*\)\..*/\1/'`
    java $name
	exit
else
	if [ "$1" == "C++" ]; then
		########### script for C++ ###########
		# students can submit more than 1 file.
		./main.exe
		exit
	else
		########### script for Java ########### 
		COUNTER=`ls -1 *.java 2>/dev/null | wc -l`
		if [ "$COUNTER" -gt 0 ]; then
			for i in *.java; do
				file=$i
			done
			#only alows 1 file.
			name=`basename $file | sed 's/\(.*\)\..*/\1/'`
			java $name
			exit
		fi

		########### script for C++ ###########
		COUNTER=`ls -1 *.cpp 2>/dev/null | wc -l`
		if [ "$COUNTER" -gt 0 ]; then
			# students can submit more than 1 file.
			./main.exe
			exit
		fi
	fi
fi