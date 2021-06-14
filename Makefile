.PHONY: clean disk all list

CCFLAGS = --target apple2enh
CAFLAGS = --target apple2enh -I/home/andrea/projects/cvs/3rdParty/a2d
LDFLAGS = -C a2da.cfg
LDLIBS  = apple2enh.lib

all: out disk list

out:
	mkdir out

out/%.o: %.s
	ca65 $(CAFLAGS) -o $@ $<

out/%.o: out/%.s
	ca65 $(CAFLAGS) -o $@ $<

out/%.s: %.c
	cc65 $(CCFLAGS) -o $@ $<
	cp $@ $@.bak # make deletes out/main.s

out/foo.da: out/main.o out/loader.o
	ld65 $(LDFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f out/*
	rm -f a2d.po

a2d.po: out/foo.da
	rm -f $@
	java -jar ${AC} -pro140 $@ a2d
	java -jar ${AC} -p $@ foo '$$f1' '0x8641' < $<
	echo "### Remember to fix the AuxType with ciderpress ###"

disk: a2d.po

list:
	java -jar ${AC} -ll a2d.po
