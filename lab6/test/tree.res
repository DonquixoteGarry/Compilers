# 0	program					child: 1
# 1	function				child: 2 3 4 8 12 16 19 22 25
# 2	type		INTEGER		child: NULL
# 3	variable	main			child: NULL
# 4	statement	DECL		child: 5 6 7
# 5	type		INTEGER		child: NULL
# 6	variable	a			child: NULL
# 7	variable	s			child: NULL
# 8	statement	ASSIGN		child: 9
# 9	assign					child: 10 11
# 10	variable	a			child: NULL
# 11	constint	10			child: NULL
# 12	statement	ASSIGN		child: 13
# 13	assign					child: 14 15
# 14	variable	s			child: NULL
# 15	constint	10			child: NULL
# 16	statement	DECL		child: 17 18
# 17	type		CHARACTER	child: NULL
# 18	variable	ch			child: NULL
# 19	statement	SCANF		child: 20 21
# 20	conststr	%c			child: NULL
# 21	variable	ch			child: NULL
# 22	statement	PRINTF		child: 23 24
# 23	conststr	%c\n			child: NULL
# 24	variable	ch			child: NULL
# 25	statement	WHILE		child: 26 40 44 47 50 54 58
# 26			child: 27
# 27	op			||			child: 28 35
# 28	op			&&			child: 29 32
# 29	op			>			child: 30 31
# 30	variable	a			child: NULL
# 31	constint	0			child: NULL
# 32	op			<=			child: 33 34
# 33	variable	a			child: NULL
# 34	constint	10			child: NULL
# 35	op			==			child: 36 39
# 36	op			%			child: 37 38
# 37	variable	a			child: NULL
# 38	constint	100			child: NULL
# 39	constint	0			child: NULL
# 40	statement	ASSIGN		child: 41
# 41	assign					child: 42 43
# 42	variable	a			child: NULL
# 43	constint	1			child: NULL
# 44	statement	PRINTF		child: 45 46
# 45	conststr	a is: %d\n			child: NULL
# 46	variable	a			child: NULL
# 47	statement	DECL		child: 48 49
# 48	type		INTEGER		child: NULL
# 49	variable	a			child: NULL
# 50	statement	ASSIGN		child: 51
# 51	assign					child: 52 53
# 52	variable	a			child: NULL
# 53	constint	10			child: NULL
# 54	statement	ASSIGN		child: 55
# 55	assign					child: 56 57
# 56	variable	s			child: NULL
# 57	variable	a			child: NULL
# 58	statement	IF			child: 59 60 63 66 70
# 59	constint	1			child: NULL
# 60	statement	PRINTF		child: 61 62
# 61	conststr	result is: %d\n			child: NULL
# 62	variable	s			child: NULL
# 63	statement	DECL		child: 64 65
# 64	type		INTEGER		child: NULL
# 65	variable	b			child: NULL
# 66	statement	ASSIGN		child: 67
# 67	assign					child: 68 69
# 68	variable	b			child: NULL
# 69	constint	10			child: NULL
# 70	statement	FOR			child: 71 85
# 71	FORargs					child: 72 81
# 72	FORargs					child: 73 78
# 73	statement	DECL		child: 74 75
# 74	type		INTEGER		child: NULL
# 75	assign					child: 76 77
# 76	variable	i			child: NULL
# 77	constint	0			child: NULL
# 78	op			<			child: 79 80
# 79	variable	i			child: NULL
# 80	variable	b			child: NULL
# 81	FORargs					child: 82
# 82	assign					child: 83 84
# 83	variable	i			child: NULL
# 84	constint	1			child: NULL
# 85	statement	PRINTF		child: 86 87
# 86	conststr	Have fun: %d\n			child: NULL
# 87	variable	i			child: NULL
# 0	program					child: 1
# 1	function				child: 2 3 4 8 12 16 19 22 25
# 2	type		INTEGER		child: NULL
# 3	variable	main			child: NULL
# 4	statement	DECL		child: 5 6 7
# 5	type		INTEGER		child: NULL
# 6	variable	a			child: NULL
# 7	variable	s			child: NULL
# 8	statement	ASSIGN		child: 9
# 9	assign					child: 10 11
# 10	variable	a			child: NULL
# 11	constint	10			child: NULL
# 12	statement	ASSIGN		child: 13
# 13	assign					child: 14 15
# 14	variable	s			child: NULL
# 15	constint	10			child: NULL
# 16	statement	DECL		child: 17 18
# 17	type		CHARACTER	child: NULL
# 18	variable	ch			child: NULL
# 19	statement	SCANF		child: 20 21
# 20	conststr	%c			child: NULL
# 21	variable	ch			child: NULL
# 22	statement	PRINTF		child: 23 24
# 23	conststr	%c\n			child: NULL
# 24	variable	ch			child: NULL
# 25	statement	WHILE		child: 26 40 44 47 50 54 58
# 26			child: 27
# 27	op			||			child: 28 35
# 28	op			&&			child: 29 32
# 29	op			>			child: 30 31
# 30	variable	a			child: NULL
# 31	constint	0			child: NULL
# 32	op			<			child: 33 34
# 33	variable	a			child: NULL
# 34	constint	10			child: NULL
# 35	op			==			child: 36 39
# 36	op			%			child: 37 38
# 37	variable	a			child: NULL
# 38	constint	100			child: NULL
# 39	constint	0			child: NULL
# 40	statement	ASSIGN		child: 41
# 41	assign					child: 42 43
# 42	variable	a			child: NULL
# 43	constint	1			child: NULL
# 44	statement	PRINTF		child: 45 46
# 45	conststr	a is: %d\n			child: NULL
# 46	variable	a			child: NULL
# 47	statement	DECL		child: 48 49
# 48	type		INTEGER		child: NULL
# 49	variable	a			child: NULL
# 50	statement	ASSIGN		child: 51
# 51	assign					child: 52 53
# 52	variable	a			child: NULL
# 53	constint	10			child: NULL
# 54	statement	ASSIGN		child: 55
# 55	assign					child: 56 57
# 56	variable	s			child: NULL
# 57	variable	a			child: NULL
# 58	statement	IF			child: 59 62 65 68 72
# 59	op			<			child: 60 61
# 60	variable	s			child: NULL
# 61	constint	120			child: NULL
# 62	statement	PRINTF		child: 63 64
# 63	conststr	result is: %d\n			child: NULL
# 64	variable	s			child: NULL
# 65	statement	DECL		child: 66 67
# 66	type		INTEGER		child: NULL
# 67	variable	b			child: NULL
# 68	statement	ASSIGN		child: 69
# 69	assign					child: 70 71
# 70	variable	b			child: NULL
# 71	constint	10			child: NULL
# 72	statement	FOR			child: 73 87
# 73	FORargs					child: 74 83
# 74	FORargs					child: 75 80
# 75	statement	DECL		child: 76 77
# 76	type		INTEGER		child: NULL
# 77	assign					child: 78 79
# 78	variable	i			child: NULL
# 79	constint	0			child: NULL
# 80	op			<			child: 81 82
# 81	variable	i			child: NULL
# 82	variable	b			child: NULL
# 83	FORargs					child: 84
# 84	assign					child: 85 86
# 85	variable	i			child: NULL
# 86	constint	1			child: NULL
# 87	statement	PRINTF		child: 88 89
# 88	conststr	Have fun: %d\n			child: NULL
# 89	variable	i			child: NULL
# 0		program					child: 1
# 1		function				child: 2 3 4 8 12 16 19 22 25
# 2		type		INTEGER		child: NULL
# 3		variable	main			child: NULL
# 4		statement	DECL		child: 5 6 7
# 5		type		INTEGER		child: NULL
# 6		variable	a			child: NULL
# 7		variable	s			child: NULL
# 8		statement	ASSIGN		child: 9
# 9		assign					child: 10 11
# 10		variable	a			child: NULL
# 11		constint	10			child: NULL
# 12		statement	ASSIGN		child: 13
# 13		assign					child: 14 15
# 14		variable	s			child: NULL
# 15		constint	10			child: NULL
# 16		statement	DECL		child: 17 18
# 17		type		CHARACTER	child: NULL
# 18		variable	ch			child: NULL
# 19		statement	SCANF		child: 20 21
# 20		conststr	%c			child: NULL
# 21		variable	ch			child: NULL
# 22		statement	PRINTF		child: 23 24
# 23		conststr	%c\n			child: NULL
# 24		variable	ch			child: NULL
# 25		statement	WHILE		child: 26 40 44 47 50 54 58
# 26				child: 27
# 27		op			||			child: 28 35
# 28		op			&&			child: 29 32
# 29		op			>			child: 30 31
# 30		variable	a			child: NULL
# 31		constint	0			child: NULL
# 32		op			<			child: 33 34
# 33		variable	a			child: NULL
# 34		constint	10			child: NULL
# 35		op			==			child: 36 39
# 36		op			%			child: 37 38
# 37		variable	a			child: NULL
# 38		constint	100			child: NULL
# 39		constint	0			child: NULL
# 40		statement	ASSIGN		child: 41
# 41		assign					child: 42 43
# 42		variable	a			child: NULL
# 43		constint	1			child: NULL
# 44		statement	PRINTF		child: 45 46
# 45		conststr	a is: %d\n			child: NULL
# 46		variable	a			child: NULL
# 47		statement	DECL		child: 48 49
# 48		type		INTEGER		child: NULL
# 49		variable	a			child: NULL
# 50		statement	ASSIGN		child: 51
# 51		assign					child: 52 53
# 52		variable	a			child: NULL
# 53		constint	10			child: NULL
# 54		statement	ASSIGN		child: 55
# 55		assign					child: 56 57
# 56		variable	s			child: NULL
# 57		variable	a			child: NULL
# 58		statement	IF			child: 59 62 65 68 72
# 59		op			<			child: 60 61
# 60		variable	s			child: NULL
# 61		constint	120			child: NULL
# 62		statement	PRINTF		child: 63 64
# 63		conststr	result is: %d\n			child: NULL
# 64		variable	s			child: NULL
# 65		statement	DECL		child: 66 67
# 66		type		INTEGER		child: NULL
# 67		variable	b			child: NULL
# 68		statement	ASSIGN		child: 69
# 69		assign					child: 70 71
# 70		variable	b			child: NULL
# 71		constint	10			child: NULL
# 72		statement	FOR			child: 73 87
# 73		FORargs					child: 74 83
# 74		FORargs					child: 75 80
# 75		statement	DECL		child: 76 77
# 76		type		INTEGER		child: NULL
# 77		assign					child: 78 79
# 78		variable	i			child: NULL
# 79		constint	0			child: NULL
# 80		op			<			child: 81 82
# 81		variable	i			child: NULL
# 82		variable	b			child: NULL
# 83		FORargs					child: 84
# 84		assign					child: 85 86
# 85		variable	i			child: NULL
# 86		constint	1			child: NULL
# 87		statement	PRINTF		child: 88 89
# 88		conststr	Have fun: %d\n			child: NULL
# 89		variable	i			child: NULL
# 0		program					child: 1
# 1		function				child: 2 3 4 8 12 16 19 22 25
# 2		type		INTEGER		child: NULL
# 3		variable	main			child: NULL
# 4		statement	DECL		child: 5 6 7
# 5		type		INTEGER		child: NULL
# 6		variable	a			child: NULL
# 7		variable	s			child: NULL
# 8		statement	ASSIGN		child: 9
# 9		assign					child: 10 11
# 10		variable	a			child: NULL
# 11		constint	10			child: NULL
# 12		statement	ASSIGN		child: 13
# 13		assign					child: 14 15
# 14		variable	s			child: NULL
# 15		constint	10			child: NULL
# 16		statement	DECL		child: 17 18
# 17		type		CHARACTER	child: NULL
# 18		variable	ch			child: NULL
# 19		statement	SCANF		child: 20 21
# 20		conststr	%c			child: NULL
# 21		variable	ch			child: NULL
# 22		statement	PRINTF		child: 23 24
# 23		conststr	%c\n			child: NULL
# 24		variable	ch			child: NULL
# 25		statement	WHILE		child: 26 40 44 47 50 54 58
# 26				child: 27
# 27		op			||			child: 28 35
# 28		op			&&			child: 29 32
# 29		op			>			child: 30 31
# 30		variable	a			child: NULL
# 31		constint	0			child: NULL
# 32		op			<			child: 33 34
# 33		variable	a			child: NULL
# 34		constint	10			child: NULL
# 35		op			==			child: 36 39
# 36		op			%			child: 37 38
# 37		variable	a			child: NULL
# 38		constint	100			child: NULL
# 39		constint	0			child: NULL
# 40		statement	ASSIGN		child: 41
# 41		assign					child: 42 43
# 42		variable	a			child: NULL
# 43		constint	1			child: NULL
# 44		statement	PRINTF		child: 45 46
# 45		conststr	a is: %d\n			child: NULL
# 46		variable	a			child: NULL
# 47		statement	DECL		child: 48 49
# 48		type		INTEGER		child: NULL
# 49		variable	a			child: NULL
# 50		statement	ASSIGN		child: 51
# 51		assign					child: 52 53
# 52		variable	a			child: NULL
# 53		constint	10			child: NULL
# 54		statement	ASSIGN		child: 55
# 55		assign					child: 56 57
# 56		variable	s			child: NULL
# 57		variable	a			child: NULL
# 58		statement	IF			child: 59 62 65 68 72
# 59		op			<			child: 60 61
# 60		variable	s			child: NULL
# 61		constint	120			child: NULL
# 62		statement	PRINTF		child: 63 64
# 63		conststr	result is: %d\n			child: NULL
# 64		variable	s			child: NULL
# 65		statement	DECL		child: 66 67
# 66		type		INTEGER		child: NULL
# 67		variable	b			child: NULL
# 68		statement	ASSIGN		child: 69
# 69		assign					child: 70 71
# 70		variable	b			child: NULL
# 71		constint	10			child: NULL
# 72		statement	FOR			child: 73 87
# 73		FORargs					child: 74 83
# 74		FORargs					child: 75 80
# 75		statement	DECL		child: 76 77
# 76		type		INTEGER		child: NULL
# 77		assign					child: 78 79
# 78		variable	i			child: NULL
# 79		constint	0			child: NULL
# 80		op			<			child: 81 82
# 81		variable	i			child: NULL
# 82		variable	b			child: NULL
# 83		FORargs					child: 84
# 84		assign					child: 85 86
# 85		variable	i			child: NULL
# 86		constint	1			child: NULL
# 87		statement	PRINTF		child: 88 89
# 88		conststr	Have fun: %d\n			child: NULL
# 89		variable	i			child: NULL
# 0		program					child: 1
# 1		function				child: 2 3 4 8 12 16 19 22 25
# 2		type		INTEGER		child: NULL
# 3		variable	main			child: NULL
# 4		statement	DECL		child: 5 6 7
# 5		type		INTEGER		child: NULL
# 6		variable	a			child: NULL
# 7		variable	s			child: NULL
# 8		statement	ASSIGN		child: 9
# 9		assign					child: 10 11
# 10		variable	a			child: NULL
# 11		constint	10			child: NULL
# 12		statement	ASSIGN		child: 13
# 13		assign					child: 14 15
# 14		variable	s			child: NULL
# 15		constint	10			child: NULL
# 16		statement	DECL		child: 17 18
# 17		type		CHARACTER	child: NULL
# 18		variable	ch			child: NULL
# 19		statement	SCANF		child: 20 21
# 20		conststr	%c			child: NULL
# 21		variable	ch			child: NULL
# 22		statement	PRINTF		child: 23 24
# 23		conststr	%c\n			child: NULL
# 24		variable	ch			child: NULL
# 25		statement	WHILE		child: 26 40 44 47 50 54 58
# 26				child: 27
# 27		op			||			child: 28 35
# 28		op			&&			child: 29 32
# 29		op			>			child: 30 31
# 30		variable	a			child: NULL
# 31		constint	0			child: NULL
# 32		op			<			child: 33 34
# 33		variable	a			child: NULL
# 34		constint	10			child: NULL
# 35		op			==			child: 36 39
# 36		op			%			child: 37 38
# 37		variable	a			child: NULL
# 38		constint	100			child: NULL
# 39		constint	0			child: NULL
# 40		statement	ASSIGN		child: 41
# 41		assign					child: 42 43
# 42		variable	a			child: NULL
# 43		constint	1			child: NULL
# 44		statement	PRINTF		child: 45 46
# 45		conststr	a is: %d\n			child: NULL
# 46		variable	a			child: NULL
# 47		statement	DECL		child: 48 49
# 48		type		INTEGER		child: NULL
# 49		variable	a			child: NULL
# 50		statement	ASSIGN		child: 51
# 51		assign					child: 52 53
# 52		variable	a			child: NULL
# 53		constint	10			child: NULL
# 54		statement	ASSIGN		child: 55
# 55		assign					child: 56 57
# 56		variable	s			child: NULL
# 57		variable	a			child: NULL
# 58		statement	IF			child: 59 62 65 68 72
# 59		op			<			child: 60 61
# 60		variable	s			child: NULL
# 61		constint	120			child: NULL
# 62		statement	PRINTF		child: 63 64
# 63		conststr	result is: %d\n			child: NULL
# 64		variable	s			child: NULL
# 65		statement	DECL		child: 66 67
# 66		type		INTEGER		child: NULL
# 67		variable	b			child: NULL
# 68		statement	ASSIGN		child: 69
# 69		assign					child: 70 71
# 70		variable	b			child: NULL
# 71		constint	10			child: NULL
# 72		statement	FOR			child: 73 87
# 73		FORargs					child: 74 83
# 74		FORargs					child: 75 80
# 75		statement	DECL		child: 76 77
# 76		type		INTEGER		child: NULL
# 77		assign					child: 78 79
# 78		variable	i			child: NULL
# 79		constint	0			child: NULL
# 80		op			<			child: 81 82
# 81		variable	i			child: NULL
# 82		variable	b			child: NULL
# 83		FORargs					child: 84
# 84		assign					child: 85 86
# 85		variable	i			child: NULL
# 86		constint	1			child: NULL
# 87		statement	PRINTF		child: 88 89
# 88		conststr	Have fun: %d\n			child: NULL
# 89		variable	i			child: NULL
# 0		program					child: 1
# 1		function				child: 2 3 4 8 12 16 19 22 25
# 2		type		INTEGER		child: NULL
# 3		variable	main			child: NULL
# 4		statement	DECL		child: 5 6 7
# 5		type		INTEGER		child: NULL
# 6		variable	a			child: NULL
# 7		variable	s			child: NULL
# 8		statement	ASSIGN		child: 9
# 9		assign					child: 10 11
# 10		variable	a			child: NULL
# 11		constint	10			child: NULL
# 12		statement	ASSIGN		child: 13
# 13		assign					child: 14 15
# 14		variable	s			child: NULL
# 15		constint	10			child: NULL
# 16		statement	DECL		child: 17 18
# 17		type		CHARACTER	child: NULL
# 18		variable	ch			child: NULL
# 19		statement	SCANF		child: 20 21
# 20		conststr	%c			child: NULL
# 21		variable	ch			child: NULL
# 22		statement	PRINTF		child: 23 24
# 23		conststr	%c\n			child: NULL
# 24		variable	ch			child: NULL
# 25		statement	WHILE		child: 26 40 44 47 50 54 58
# 26				child: 27
# 27		op			||			child: 28 35
# 28		op			&&			child: 29 32
# 29		op			>			child: 30 31
# 30		variable	a			child: NULL
# 31		constint	0			child: NULL
# 32		op			<			child: 33 34
# 33		variable	a			child: NULL
# 34		constint	10			child: NULL
# 35		op			==			child: 36 39
# 36		op			%			child: 37 38
# 37		variable	a			child: NULL
# 38		constint	100			child: NULL
# 39		constint	0			child: NULL
# 40		statement	ASSIGN		child: 41
# 41		assign					child: 42 43
# 42		variable	a			child: NULL
# 43		constint	1			child: NULL
# 44		statement	PRINTF		child: 45 46
# 45		conststr	a is: %d\n			child: NULL
# 46		variable	a			child: NULL
# 47		statement	DECL		child: 48 49
# 48		type		INTEGER		child: NULL
# 49		variable	a			child: NULL
# 50		statement	ASSIGN		child: 51
# 51		assign					child: 52 53
# 52		variable	a			child: NULL
# 53		constint	10			child: NULL
# 54		statement	ASSIGN		child: 55
# 55		assign					child: 56 57
# 56		variable	s			child: NULL
# 57		variable	a			child: NULL
# 58		statement	IF			child: 59 62 65 68 72
# 59		op			<			child: 60 61
# 60		variable	s			child: NULL
# 61		constint	120			child: NULL
# 62		statement	PRINTF		child: 63 64
# 63		conststr	result is: %d\n			child: NULL
# 64		variable	s			child: NULL
# 65		statement	DECL		child: 66 67
# 66		type		INTEGER		child: NULL
# 67		variable	b			child: NULL
# 68		statement	ASSIGN		child: 69
# 69		assign					child: 70 71
# 70		variable	b			child: NULL
# 71		constint	10			child: NULL
# 72		statement	FOR			child: 73 87
# 73		FORargs					child: 74 83
# 74		FORargs					child: 75 80
# 75		statement	DECL		child: 76 77
# 76		type		INTEGER		child: NULL
# 77		assign					child: 78 79
# 78		variable	i			child: NULL
# 79		constint	0			child: NULL
# 80		op			<			child: 81 82
# 81		variable	i			child: NULL
# 82		variable	b			child: NULL
# 83		FORargs					child: 84
# 84		assign					child: 85 86
# 85		variable	i			child: NULL
# 86		constint	1			child: NULL
# 87		statement	PRINTF		child: 88 89
# 88		conststr	Have fun: %d\n			child: NULL
# 89		variable	i			child: NULL
