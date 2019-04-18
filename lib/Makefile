current_dir  := $(shell pwd)
build_dir	 := $(addsuffix /build,$(current_dir))

codecs		 := libogg libvorbis libflac libmad libsoundio

clean_codecs := $(addsuffix clean,$(codecs))
make_codecs  := $(addsuffix make,$(codecs))

all: $(build_dir) $(make_codecs)

$(build_dir):
	mkdir -p $@

$(build_dir)clean: 
	rm -rf $(build_dir)

libsoundiobuild:
	cd $(patsubst %build,%,$@) && \
		mkdir -p build && cd build && \
		cmake -DCMAKE_INSTALL_PREFIX:PATH=$(build_dir) ..

libsoundiomake: libsoundiobuild
	make -C $(patsubst %make,%,$@)/build && \
		make -C $(patsubst %make,%,$@)/build install

libsoundioclean:
	rm -rf $(patsubst %clean,%,$@)/build

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

libmadbuild:
	cd $(patsubst %build,%,$@) && \
		patch -Np1 -i ../libmad-0.15.1b-fixes-1.patch
	cd $(patsubst %build,%,$@) && pwd \
		sed "s@AM_CONFIG_HEADER@AC_CONFIG_HEADERS@g" -i configure.ac && \
		touch NEWS AUTHORS ChangeLog  && \
		autoreconf -fi && \
		./configure --prefix=$(build_dir) --disable-static

libmadmake: libmadbuild
	make -C $(patsubst %make,%,$@) && \
		make -C $(patsubst %make,%,$@) install

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

%clean: %
	@echo Cleaning $<...
	make -C $(patsubst %build,%,$<) clean
	@cd $< && git clean -fd

.PHONY: clean all
