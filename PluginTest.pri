
CONFIG(debug,debug|release){
DEFINES*=_DEBUG
}else{
DEFINES*=NDEBUG
}

win32-msvc*{

CONFIG(debug,debug|release){
DESTDIR_THE_PROJECT=$$PWD/binlib/msvc_debug_bin
}else{
DESTDIR_THE_PROJECT=$$PWD/binlib/msvc_release_bin
}

}else{

CONFIG(debug,debug|release){
DESTDIR_THE_PROJECT=$$PWD/binlib/common_debug_bin
}else{
DESTDIR_THE_PROJECT=$$PWD/binlib/common_release_bin
}

}



