
build:
	@#pio -c clion run  -e uno  | cat
	cmake --build cmake-build-uno --target Production
init:
	pio project init --ide clion | cat
clean:
	rm -rf .pio cmake-build-* CMakeListsPrivate.txt
