int camera_initialize(){
    camera_open_black();
    int a=0;
    while(a<6){
        camera_update();
        a=a+1;
    }
    return 0;
}
int full_check(int c){ 
    int a=0;
    int b=0;
    while(a<30){  
        camera_update();
        if(get_object_count(c)>0){b=b+1;}
        a=a+1;
    }
    if(b>10){return 1;}
    else{return 0;}
    camera_close();
}
int camera_center(int color){
    camera_initialize();
    if(full_check(color)==1){
        while(1){
            motor(0,(get_object_center_x(color,0)-80));
            motor(3,(80-(get_object_center_x(color,0))));
        }
    }
}