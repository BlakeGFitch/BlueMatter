#include <pktracefile_api.hpp>

const char * pkTraceFileName ;


main(int argc, char **argv)
{
  int i = 1;
  int quit = 0;

  TraceFileAccess Accessor;
  TraceLineObject *CurrentTraceObject;
  char             FileName[1024];

  FileName[0]     = 0x00;

  while( i < argc && !quit)
  {
    if ( argv[i][0] == '-' )
    {
      switch( argv[i][1] )
      {
        case 'f' :
          if ( i + 1 < argc )
          {
            strcpy( FileName,argv[++i] );
          }
          break;

          default:
             break;
      }
      i++;

    }
    else
    {
      quit = 1;
    }
  }

  printf("About to open [%s]\n",FileName);
  Accessor.OpenFile(FileName);

  printf("Number of traces [%d]\n",Accessor.GetNumTraces());

  CurrentTraceObject = Accessor.GetNextTrace();

  while (CurrentTraceObject != NULL)
  {

    printf("CurrentTraceObject.GetTraceName() [%s]\n",
                                            CurrentTraceObject->GetTraceName());


    printf("Num hits in trace [%d]\n",CurrentTraceObject->GetNumPoints());
    for( int p=0;p<CurrentTraceObject->GetNumPoints();p+=1)
      {
    printf("Hit number [%d] at [%lld]\n",p,
                                     CurrentTraceObject->GetLTimeAtPosition(p));
      }

    delete CurrentTraceObject;
    CurrentTraceObject = Accessor.GetNextTrace();
  }

}
