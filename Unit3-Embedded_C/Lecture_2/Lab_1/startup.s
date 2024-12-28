.global reset                         @@ make reset label Global to be seen from all files  


reset : 
		ldr sp, = stack_top           @@ Init. Stack Pointer to stack top
		bl main                       @@ Branch label to main label 
		b stop                        @@ Branch stop if we return from main 

stop :
		b stop                        @@ Branch to stop and enter infinite loop
		