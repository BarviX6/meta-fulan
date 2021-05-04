CXXFLAGS_append_sh4 += " -std=c++11 -fPIC -fno-strict-aliasing "

DEPENDS_append_sh4 += "\
	libmme-image \
	"

RDEPENDS_${PN}_append_sh4 += "\
	alsa-utils-amixer-conf \
	"

SRC_URI_sh4 = "${GITHUB_URI}/BarviX6/enigma2-openpli.git;branch=develop"


