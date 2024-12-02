# push_swap

Sorting numbers using two stacks and turkey sort.

## 📝 General

Goal of the project is to sort numbers using two stacks and least amounts of commands.

The available stacks are `a` and `b`. Numbers are initially stored in stack `a` in random order.

Algorithm uses `turkey sort` where each number targets their `closest` smallest or largest `number` before push command. Doing so arranges numbers into stack `b` in `decending` order and pushing them back to stack `a` reverses it to `ascending` order.

Stacks are build as `doubly linked lists` to allow straight forward operation of `commands`.

## ⚡ Usage

You can run `push_swap` by giving it numbers in two ways. It prints the commands to `STDOUT`. Incorrect input results to `Error`.

```bash
./push_swap 4 0 1 3 2
```

```bash
./push_swap "4 0 1 3 2"
```

```
pb
pb
rra
sa
pa
pa
ra
```

`Checker` can be used the same way, then write commands to `STDIN` and finish input with `Crtl + D`. 

If stack was sorted correctly, `OK` is shown in `STDOUT` else writes `KO`. Incorrect command results into `Error`.

Other option is to assign numbers into `ARG` and use `push_swap` to pass commands into checker.

```bash
./checker "4 0 1 3 2"
```

```
pb
pb
rra
sa
pa
pa
ra
OK
```

```bash
ARG="4 0 1 3 2"; ./push_swap $ARG | ./checker $ARG
```

## 📊 Commands

Only following `commands` are allowed by the algorithm. Each time command is triggered, run the operation and print it to `STDOUT`.

| Command | Description                                                      |
|---------|-----------------------------------------------------------------------------|
| sa      | Swap the first 2 elements at the top of stack a. |
| sb      | Swap the first 2 elements at the top of stack b. |
| ss      | Perform `sa` and `sb` at the same time.          |
| pa      | Push first element of stack b as first element to stack a. |
| pb      | Push first element of stack a as first element to stack b. |
| ra      | Shift up all elements of stack a by 1, first becomes last. |
| rb      | Shift up all elements of stack b by 1, first becomes last. |
| rr      | Perform `ra` and `rb` at the same time.          |
| rra     | Shift down all elements of stack a by 1, last becomes first. |
| rrb     | Shift down all elements of stack b by 1, last becomes first. |
| rrr     | Perform `rra` and `rrb` at the same time.        |

```c
void rra(t_stack **a, bool checker)
{
  reverse(a);
  if (!checker)
    ft_printf("rra\n");
}
```

```c
static void reverse(t_stack **s)
{
  t_stack  *bottom;

  if (!s || !*s || !(*s)->next)
    return ;
  bottom = (t_stack *)ft_lstlast((t_list *)*s);
  bottom->prev->next = NULL;
  bottom->next = *s;
  bottom->prev = NULL;
  *s = bottom;
  bottom->next->prev = bottom;
}
```

## ♻️ Resources

[push_swap TUTORIAL!](https://www.youtube.com/watch?v=wRvipSG4Mmk) video presentation on turkey sort algorithm.

[push_swap_tester](https://github.com/LeoFu9487/push_swap_tester) for basic tests and leaks testing.

[Push-Swap-Tester](https://github.com/gemartin99/Push-Swap-Tester) more testing and excellent performance reports.

[PushSwap-ProChecker](https://github.com/ailopez-o/42Barcelona-PushSwap-ProChecker) fantastic tool to visualize your algorithm.

[Push Swap Visualizer](https://push-swap-visualizer.vercel.app/) simple way to generate numbers for testing.

For general information, please refer the landing page.

### Cheers and good luck! 🥳