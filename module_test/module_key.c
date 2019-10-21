

typedef int (*func_ptr)(int);



static void init(char,char **);
static void quite(char argc,char **argv)
{
	int i;
	printf("\n\rKey Quite! ");
	/*printf("\n\ryour argv is :");
	if(argc>0)
	{
		for(i=0;i<argc;i++)
		{
			printf("\n\r");
			printf(argv[i]);
		}
	}*/
	commandrestore();
	
	//key_close();

  
}

static void init(char argc,char **argv)
{
	int i;
	printf("\n\rKey Test ");

  commandsave(); 
  init_command();
  

	register_command(quite,"quite");

	//KeyInit();

	
}


static int moduleKey_init (int i )
{
	register_command(init,"key");
	printf("	%s\n",__FUNCTION__);
	return 1;	                    
}

static func_ptr modulexxx_init_func __attribute__ ((used)) __attribute__ ((section(".customized"))) = moduleKey_init;
