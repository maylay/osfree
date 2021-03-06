#ifndef _MOUNTREG_H_
#define _MOUNTREG_H_





struct I_Fs_srv {
    char *server;
    char *drive;
};
typedef struct I_Fs_srv   I_Fs_srv_t;

/* Finds out which I_Fs_srv to direct the path to. */
struct FSRouter {
    /*FSRouter(void);*/
    /*void add(I_Fs_srv*);
    I_Fs_srv* route(char);
    void test(void);*/
    I_Fs_srv_t **fs_srv_arr_;
    int max_drv; 
    int srv_num_; /* Fritt nummer att l�gga in enhetsserver p�. */
};



void I_Fs_srv_init(I_Fs_srv_t *s); 

void I_Fs_srv_init2(I_Fs_srv_t *s, char *strsrv, char *drv);

char get_drv(const char *s_path);

void os2_fname_to_fileprov_fname(const char *fname,char *filename);

void FSRouter_add(struct FSRouter *s, struct I_Fs_srv *fs_srv_);

I_Fs_srv_t* FSRouter_route(struct FSRouter *s, char);

void FSRouter_test(struct FSRouter *s);

void FSRouter_init(struct FSRouter *s);

#endif
