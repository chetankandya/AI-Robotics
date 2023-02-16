;; Auto-generated. Do not edit!


(when (boundp 'air_lab3::ExecuteTst)
  (if (not (find-package "AIR_LAB3"))
    (make-package "AIR_LAB3"))
  (shadow 'ExecuteTst (find-package "AIR_LAB3")))
(unless (find-package "AIR_LAB3::EXECUTETST")
  (make-package "AIR_LAB3::EXECUTETST"))
(unless (find-package "AIR_LAB3::EXECUTETSTREQUEST")
  (make-package "AIR_LAB3::EXECUTETSTREQUEST"))
(unless (find-package "AIR_LAB3::EXECUTETSTRESPONSE")
  (make-package "AIR_LAB3::EXECUTETSTRESPONSE"))

(in-package "ROS")





(defclass air_lab3::ExecuteTstRequest
  :super ros::object
  :slots (_tst_file ))

(defmethod air_lab3::ExecuteTstRequest
  (:init
   (&key
    ((:tst_file __tst_file) "")
    )
   (send-super :init)
   (setq _tst_file (string __tst_file))
   self)
  (:tst_file
   (&optional __tst_file)
   (if __tst_file (setq _tst_file __tst_file)) _tst_file)
  (:serialization-length
   ()
   (+
    ;; string _tst_file
    4 (length _tst_file)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _tst_file
       (write-long (length _tst_file) s) (princ _tst_file s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _tst_file
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _tst_file (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass air_lab3::ExecuteTstResponse
  :super ros::object
  :slots (_success _error_message ))

(defmethod air_lab3::ExecuteTstResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:error_message __error_message) "")
    )
   (send-super :init)
   (setq _success __success)
   (setq _error_message (string __error_message))
   self)
  (:success
   (&optional (__success :null))
   (if (not (eq __success :null)) (setq _success __success)) _success)
  (:error_message
   (&optional __error_message)
   (if __error_message (setq _error_message __error_message)) _error_message)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; string _error_message
    4 (length _error_message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; string _error_message
       (write-long (length _error_message) s) (princ _error_message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _error_message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _error_message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass air_lab3::ExecuteTst
  :super ros::object
  :slots ())

(setf (get air_lab3::ExecuteTst :md5sum-) "44f7b4ced43e85a05e62b2b38ffc3b46")
(setf (get air_lab3::ExecuteTst :datatype-) "air_lab3/ExecuteTst")
(setf (get air_lab3::ExecuteTst :request) air_lab3::ExecuteTstRequest)
(setf (get air_lab3::ExecuteTst :response) air_lab3::ExecuteTstResponse)

(defmethod air_lab3::ExecuteTstRequest
  (:response () (instance air_lab3::ExecuteTstResponse :init)))

(setf (get air_lab3::ExecuteTstRequest :md5sum-) "44f7b4ced43e85a05e62b2b38ffc3b46")
(setf (get air_lab3::ExecuteTstRequest :datatype-) "air_lab3/ExecuteTstRequest")
(setf (get air_lab3::ExecuteTstRequest :definition-)
      "string tst_file         # Name of the TST file to execute
---
bool success            # Whether the execution was succesful
string error_message    # Error message if the execution was unsuccessful

")

(setf (get air_lab3::ExecuteTstResponse :md5sum-) "44f7b4ced43e85a05e62b2b38ffc3b46")
(setf (get air_lab3::ExecuteTstResponse :datatype-) "air_lab3/ExecuteTstResponse")
(setf (get air_lab3::ExecuteTstResponse :definition-)
      "string tst_file         # Name of the TST file to execute
---
bool success            # Whether the execution was succesful
string error_message    # Error message if the execution was unsuccessful

")



(provide :air_lab3/ExecuteTst "44f7b4ced43e85a05e62b2b38ffc3b46")


