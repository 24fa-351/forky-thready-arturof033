forky: forky.c \
		pattern1.c pattern2.c \
		pattern1.h pattern2.h
	gcc -o forky forky.c pattern1.c pattern2.c

results: forky
	(echo "Starting Process 1:" && ./forky 1 ${shell bc --expression="$$RANDOM % 15 + 5"} && \
	echo "Starting Process 2:" && ./forky 2 ${shell bc --expression="$$RANDOM % 15 + 5"}) > results.txt

clean:
	rm -f forky



