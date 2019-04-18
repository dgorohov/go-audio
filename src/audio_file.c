#include "audio_file.h"

struct audio_format {
	int	    (*open)(struct audio_file *fd, const char *ext);
	void	(*close)(struct audio_file *fd);
	size_t	(*read)(struct audio_file *fd, int16_t *buf, size_t len);
	void	(*seek)(struct audio_file *fd, int len, int rel);
};
