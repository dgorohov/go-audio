current_dir  := $(shell pwd)
build_dir	 := $(addsuffix /build,$(current_dir))

codecs		 := libogg libvorbis libflac liblame

clean_codecs := $(addsuffix clean,$(codecs))
make_codecs  := $(addsuffix make,$(codecs))

all: $(build_dir) $(make_codecs)

$(build_dir):
	mkdir -p $@

$(build_dir)clean: 
	rm -rf $(build_dir)

libflacbuild:
	cd $(patsubst %build,%,$@) && \
		./autogen.sh && \
		./configure --prefix=$(build_dir) \
			--with-ogg-includes=$(build_dir)/include \
			--with-ogg-libraries=$(build_dir)/lib \
			--disable-oggtest \
			--disable-ogg \
			--disable-cpplibs \
			--disable-xmms-plugin \
			--disable-examples

liblamebuild:
	cd $(patsubst %build,%,$@) && \
		./configure --enable-nasm \
			--disable-gtktest \
			--disable-frontend \
    		--prefix=$(build_dir)

liboggbuild:
	cd $(patsubst %build,%,$@) && \
		./autogen.sh && \
			./configure --prefix=$(build_dir)

libvorbisbuild:
	cd $(patsubst %build,%,$@) && \
		./autogen.sh && \
		./configure --prefix=$(build_dir) \
    		--with-ogg-includes=$(build_dir)/include \
    		--with-ogg-libraries=$(build_dir)/lib \
    		--disable-oggtest

%make: %build
	make -C $(patsubst %build,%,$<) && \
		make -C $(patsubst %build,%,$<) install

clean: $(build_dir)clean $(clean_codecs)
	@echo "Done"

liblameclean:
	@echo "Skip clean as it doesn't exists in liblame"

%clean: %
	@echo Cleaning $<...
	make -C $(patsubst %build,%,$<) clean
	@cd $< && git clean -fd

.PHONY: clean all
