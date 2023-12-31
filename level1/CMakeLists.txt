project(level1)

add_executable(p01_running_letter p01_running_letter/main.c
)

add_executable(p02_is_prime p02_is_prime/main.c
        p02_is_prime/prime.h
)

add_executable(p03_all_primes p03_all_primes/main.c
        p02_is_prime/prime.h)

add_executable(p04_goldbach p04_goldbach/main.c
        p02_is_prime/prime.h)

add_executable(p05_encrypt_decrypt p05_encrypt_decrypt/main.c)

add_executable(p06_hanoi p06_hanoi/main.c)

add_executable(p07_maze p07_maze/main.c)

add_executable(p08_push_boxes p08_push_boxes/main.c)

add_executable(p09_linked_list p09_linked_list/main.c
        p09_linked_list/Queue.h)

add_executable(p10_warehouse p10_warehouse/main.c)

add_executable(p11_bubble_sort p11_bubble_sort/main.c)

add_executable(p12_selection_sort p12_selection_sort/main.c)

add_executable(p13_insertion_sort p13_insertion_sort/main.c)

add_executable(p14_linked_list p14_linked_list/main.c)

add_executable(p15_reverse_polish_notation p15_reverse_polish_notation/main.c)

add_executable(p16_large_hex_addition p16_large_hex_addition/main.c)