
for i in src/*.jack;do
	cat $i | astyle --indent=force-tab=8 --style=linux  --mode=java | \
		sed 's/\t//1' > indent.tmp
	if test $? -eq 0; then
		 cat indent.tmp > $i
	fi
done

for i in src/*.[ch];do
	cat $i | astyle --indent=force-tab=8 --style=linux  --mode=c | \
		cat > indent.tmp
	if test $? -eq 0; then
		 cat indent.tmp > $i
	fi
done

rm -f indent.tmp

