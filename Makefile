opt:
	gcc decode.c -o decode
oldopt:
	gcc decode_opt_backup.c -o decode
profile:
	gcc -pg -O0 decode.c

unop:
	gcc decode_unoptimized.c -o decode
unop-profile:
	gcc -pg -O0 decode_unoptimized.c

debug:
	gcc -O0 -g decode.c -o decode
