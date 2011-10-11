let s:sPath = expand('<sfile>:p:h')
let g:indexer_ctagsCommandLineOptions="-R --c++-kinds=+p --fields=+iaS --extra=+q"
let g:indexer_indexerListFilename = s:sPath.'/.indexer_files'

