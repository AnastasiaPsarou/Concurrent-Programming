int mysem_create(struct sembuf op, int initial_value);

void mysem_down(struct sembuf op, int semid);

int mysem_up(int semid);

void mysem_destroy(int semid);
