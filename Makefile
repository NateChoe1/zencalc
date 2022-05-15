zen: scratch.c
	$(CC) $< -o $@
	./$@ > $<

scratch.c: zen.c
	cp $< $@

restart:
	rm scratch.c zen
