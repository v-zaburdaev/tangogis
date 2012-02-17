let s:sPath = expand('<sfile>:p:h')
let g:indexer_ctagsCommandLineOptions="-R --c++-kinds=+pl --fields=+iaS --extra=+q"
let g:indexer_indexerListFilename = s:sPath.'/.indexer_files'
let g:pyclewn_args=" --gdb=async,". $INDEXER_PROJECT_ROOT . "/../build/tango_pycl"
map <F9> :make -f ../build/Makefile<cr>
vmap <F9> <esc>:make -f ../build/Makefile<cr>i
imap <F9> <esc>:make -f ../build/Makefile<cr>i

