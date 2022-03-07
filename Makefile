
PIO=pio

default: init

init:
	$(PIO) project init --ide clion | cat

build:
	@#pio -c clion run  -e uno  | cat
	cmake --build cmake-build-uno --target Production

upload:
	$(PIO) -c clion run --target upload -e uno

remote:
	$(PIO) remote run --target upload -e uno

clean:
	rm -rf .pio cmake-build-* CMakeListsPrivate.txt
