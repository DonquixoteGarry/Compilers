type→int | char | float | double | bool
	idlist→idlist,id|id
	id → id-nondigit 
	| id identifier-nondigit 
	| id digit 
	id-nondigit → _|a|b|...|z|A|B|...|Z
	digit → 0|1|2|3|4|5|6|7|8|9
	unary-expr →
	id|add-expr|unary_op unary_expr
	unary-op → ‘+’|‘-’|‘!’
	assign-expr→
	unary-expr = assign-expr
	|logical-expr | expr
	expr → add-expr
	mul-expr → unary-expr
	| mul-expr * unary-expr
	| mul-expr / unary-expr
	| mul-expr % unary-expr
	add-expr → mul-expr
	| add-expr + mul-expr
	| add-expr - mul-expr
	logical-expr → lor-expr
	rel-expr → add-expr 
	| rel-expr '<' add-expr 
	| rel-expr '>' add-expr 
	| rel-expr '<='add-expr 
	| rel-expr '>='add-expr 
	eq-expr → rel-expr 
	| eq-expr '==' rel-expr
	| eq-expr '!=' rel-expr
	land-expr → eq-expr
	|land-expr‘&&’eq-expr
	lor-expr → land-expr
	| lor-expr ‘||’ land-expr
	stmt → if (logical-expr) stmt else stmt 
	| while (logical-expr)
	| for (expr; logical-expr; expr)stmt
	funcdef → type funcname(paralist)stmt 
	paralist → paralist, paradef|paradef|ϵ 
	paradef → type id 