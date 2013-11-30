if [ "$1" == "Java" ]; then
	########### script for Java ########### 
	for i in *.java; do
		file=$i
	done
	#only alows 1 file.
	javac $file
	exit
else
	if [ "$1" == "C++" ]; then
		########### script for C++ ###########
		for i in *.cpp; do
			g++ -c -Wall -g $i
			temp=`basename $i | sed 's/\(.*\)\..*/\1/'`
			name="$name $temp.o"
		done
		# students can submit more than 1 file.
		g++ -Wall -g -o main.exe $name
		exit
	else
		########### script for Java ########### 
		COUNTER=`ls -1 *.java 2>/dev/null | wc -l`
		if [ "$COUNTER" -gt 0 ]; then
			for i in *.java; do
				file=$i
			done
			#only alows 1 file.
			javac $file
			exit
		fi

		########### script for C++ ###########
		COUNTER=`ls -1 *.cpp 2>/dev/null | wc -l`
		if [ "$COUNTER" -gt 0 ]; then
			for i in *.cpp; do
				g++ -c -Wall -g $i
				temp=`basename $i | sed 's/\(.*\)\..*/\1/'`
				name="$name $temp.o"
			done
			# students can submit more than 1 file.
			g++ -Wall -g -o main.exe $name
			exit
		fi
	fi
fi