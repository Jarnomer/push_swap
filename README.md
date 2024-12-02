<h1 align="center">
  "push_swap"
</h1>

<p align="center">
	<b><i>Sorting numbers using two stacks and turkey sort.</i></b><br>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Solo-violet?style=for-the-badge" alt="solo">
  <img src="https://img.shields.io/badge/Score-125%2F100-lightgreen?style=for-the-badge" alt="score">
	<img src="https://img.shields.io/github/languages/code-size/Jarnomer/push_swap?style=for-the-badge&color=lightorange" alt="GitHub code size in bytes">
  <img src="https://img.shields.io/github/languages/top/Jarnomer/push_swap?style=for-the-badge&logo=c&label=%20&labelColor=gray&color=lightblue" alt="GitHub top language">
</p>

## 📝 General

Goal of the project is to sort numbers using two stacks and least amounts of commands.

The available stacks are `a` and `b`. Numbers are initially stored in stack `a` in random order.

Algorithm uses `turkey sort` where each number targets their `closest` smallest or largest `number` before push command. Doing so arranges numbers into stack `b` in `decending` order and pushing them back to stack `a` reverses it to `ascending` order.

Stacks are build as `doubly linked lists` to allow straight forward operation of `commands`.

## ⚡ Usage

`push_swap` can be run by giving it numbers in two ways. It prints the commands to `STDOUT`. Incorrect input results to `Error`.

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

`checker` can be used the same way, then write commands to `STDIN` and finish input with `Crtl + D`. 

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

## 4️⃣2️⃣ Footer

For my other 42 project and general information, please refer the [landing page](https://github.com/Jarnomer/Hive42).

I have also created error handling [unit testers](https://github.com/Jarnomer/Hive42) for `pipex`, `so_long` and `cub3d`.

### Cheers and good luck! 🥳