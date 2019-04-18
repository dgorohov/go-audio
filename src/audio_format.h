#include "audio_file.h"

struct audio_file;

#ifdef BUILD_MP3
int mp3_open(struct audio_file *fd, const char *ext);
void mp3_close(struct audio_file *fd);
size_t mp3_read(struct audio_file *fd, int16_t *buf, size_t len);
void mp3_seek(struct audio_file *fd, int len, int rel);
#endif

#ifdef BUILD_FLAC
int flac_open(struct audio_file *fd, const char *ext);
void flac_close(struct audio_file *fd);
size_t flac_read(struct audio_file *fd, int16_t *buf, size_t len);
void flac_seek(struct audio_file *fd, int len, int rel);
#endif

#ifdef BUILD_VORBIS
int vorbis_open(struct audio_file *fd, const char *ext);
void vorbis_close(struct audio_file *fd);
size_t vorbis_read(struct audio_file *fd, int16_t *buf, size_t len);
void vorbis_seek(struct audio_file *fd, int len, int rel);
#endif
