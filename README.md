# In development

## Purpose

To create a golang bindings for the popular audio frameworks, like vorbis, flac, ac3 etc.

## Libraries included:
- libogg
- libvorbis
- libflac
- liblame
- ...

## Prerequisites:
- `pkg-config` to be installed

## How to build
```
mkdir build
export BUILD_DIR=`pwd`
cd lib/libogg
./autogen.sh && ./configure --prefix=$BUILD_DIR && make && make install
cd ../../lib/libvorbis
./autogen.sh && ./configure --prefix=$BUILD_DIR \
    --with-ogg-includes=$BUILD_DIR/include \
    --with-ogg-libraries=$BUILD_DIR/lib \
    --disable-oggtest

cd ../../lib/libflac
./autogen.sh && ./configure --prefix=$BUILD_DIR \
     --with-ogg-includes=$BUILD_DIR/include \
     --with-ogg-libraries=$BUILD_DIR/lib \
     --disable-oggtest

cd ../../lib/liblame
./configure --enable-mp3rtp --enable-nasm --disable-gtktest \
    --prefix=$BUILD_DIR

```
