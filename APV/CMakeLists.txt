set(ARTEMIS_PATH /opt/local/artemis CACHE PATH "path to artemis install" FORCE)
set(ARTEMIS_OEDO_PATH /home/sh13/art_analysis/user/yokoyama/src-oedo CACHE PATH "path to artemis src-oedo" FORCE)
set(ARTEMIS_SRC_PATH /home/ota/repos/artemis/sources/ CACHE PATH "path to artemis src" FORCE)
set(ARTEMIS_SHARE_PATH /home/ota/repos/artemis-share/ CACHE PATH "path to artemis share" FORCE)
set(ARTEMIS_CAT_PATH /home/ota/repos/artemis-cat-src/ CACHE PATH "path to artemis cat" FORCE)
set(GETDECODER_PATH /opt/local/GETDecoder/ CACHE PATH "path to get decoder" FORCE)

include_directories(${ARTEMIS_PATH}/include)
include_directories(${ARTEMIS_OEDO_PATH})
include_directories(core/include)
include_directories(decoder/include)
include_directories(data/include)

link_directories(${ARTEMIS_PATH}/lib)
link_directories(${ARTEMIS_OEDO_PATH})
link_directories(${ARTEMIS_SHARE_PATH}/src)
link_directories(${ARTEMIS_CAT_PATH})
link_directories(${GETDECODER_PATH}/lib)


set(ARTLIBS catcmd catloop catcore artcont catmc artdecoder artridf artrdf arthist artparam oedo CAT user GETDecoder)

add_subdirectory(data)
add_subdirectory(core)
add_subdirectory(decoder)
add_subdirectory(evtbuilder)
add_subdirectory(merger)
add_subdirectory(scripts)