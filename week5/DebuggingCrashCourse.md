

# Debugging crash course

### Basic concepts

- Debugging?   
- Breakpoints - add, remove, enable, disable  

### Debugging windows

- Call stack  
- Data explorer / Variables (наименование в CodeBlocks: Watches)  
- Breakpoints  

### Debugging actions

- Resume (Continue)  
- Step over (Next line)  
- Step into  
            - Демо с JediOrder::remove(). Гледайте Call stack-а!  
- Step out  
- Run to this line  
- Set next statement (Change CPU to this line)  

Каква е разликата между *Run to this line* и *Set next statement*?

### Navigation
- Jump back / forward  

### Data explorer (Variables / Watches)

- Local variables  
- Add custom variables  
- How to watch dynamic arrays?  
        - `*some_pointer@3`  (GDB)  
        - `*arr@size`  (GDB only)  
        - `some_pointer, 3` (Visual Studio)  
        - `*(int(*)[3])some_pointer`  
        - Codeblocks има лесен начин, но губим възможността размерът да е променлива  


### Variables modification

- **Change value** of a variable *at runtime*  
- Set **Watch point** on a variable (наименование в CodeBlocks: Add data breakpoint for a variable)  