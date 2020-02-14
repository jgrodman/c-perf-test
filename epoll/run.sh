rm out.txt
for i in {1..5}
do
	./test >> out.txt
done

awk '{s+=$1}END{print "ave:",s/NR}' RS="\n" out.txt
