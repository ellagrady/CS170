; Ella Grady
; CS 170 Assignment 2
; February 21, 2022


(define (fibb n f2 f1) ; helper for fib
  (cond ((null? n) #f)
        ((= n 0) f2) ; return f2 if n = 0
        ((= n 1) f1) ; return f1 if n = 1
        (#t (fibb (- n 1) f1 (+ f2 f1))))) ; otherwise do next stage of fibbonaci
; (fib n) returns the n-th Fibonacci number
(define (fib n)
  (fibb n 0 1)) ; starts fib from f2 = 0 and f1 = 1

(define (testfib fibFn)
   (equals? (map fibFn '(0 1 2 3 4 5 6 7 8 9 10)) 
                       '(0 1 1 2 3 5 8 13 21 34 55)))

; (nth alist n) returns the n-th element in alist
(define (nth alist n)
  (cond ((null? alist) #f)
        ((> n (length alist)) '()) ; if n > length of list return empty list
        ((= (length alist) (+ (- (length alist) 1) n)) (car alist)) ; if length of list equal to ((length - 1) + n) return first item in list
        (#t (nth (cdr alist) (- n 1))))) ; otherwise recursively call on list minus the first item 

; (contains alist item) returns #t if item can be found in any level of alist (regardless of nested lists), and #f otherwise
(define (contains alist item) 
  (cond ((null? alist) #f)
        ((equal? (car alist) item) #t) ; if first item in list = item return item
        ((list? (car alist)) (contains (car alist) item)) ; if the first item in the list is a list check if the item is in that list
        (#t (contains(cdr alist) item)))) ; otherwise check rest of list

; helper for listleaves
(define (emptylist bt helper)
  (cond ((and (null? (cadr bt)) ; if both are null put leaf into list 
             (null? (caddr bt)))
         (cons (car bt) helper))
        ((and (null? (cadr bt)) (not (null? (caddr bt)))) (emptylist (caddr bt) helper)) ; if first null and second not check second
        ((and (not(null? (cadr bt))) (null? (caddr bt))) (emptylist (cadr bt) helper)) ; if first not null and second null check first
        (#t  (append (emptylist (cadr bt) helper) (emptylist (caddr bt) helper))))) ; otherwise add the return of emptylist on next values

; (listleaves bt) lists the leaves in the binary tree bt
(define (listleaves bt)
  (emptylist bt ()))

; (bsearch item bst) returns #t if item is found in the binary search tree bst
;       assumes item is an integer and that the elements of the tree bst are integers
;       uses binary search algorithm
(define (bsearch item bst)
  (cond ((or ( null? bst) (null? item)) #f)
        ((< item (car bst)) (bsearch item (cadr bst))) ; if item < first item in bst call bsearch on next item in list
        ((> item (car bst)) (bsearch item (caddr bst))) ; if item > first item in bst call bsearch on third item in list
        ((= item (car bst)) #t) ; if item = first item in bst return true
        (#t (bsearch item (car bst))))) ; otherwise continue through list


