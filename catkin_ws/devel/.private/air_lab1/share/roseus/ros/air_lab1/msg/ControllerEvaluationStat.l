;; Auto-generated. Do not edit!


(when (boundp 'air_lab1::ControllerEvaluationStat)
  (if (not (find-package "AIR_LAB1"))
    (make-package "AIR_LAB1"))
  (shadow 'ControllerEvaluationStat (find-package "AIR_LAB1")))
(unless (find-package "AIR_LAB1::CONTROLLEREVALUATIONSTAT")
  (make-package "AIR_LAB1::CONTROLLEREVALUATIONSTAT"))

(in-package "ROS")
;;//! \htmlinclude ControllerEvaluationStat.msg.html


(defclass air_lab1::ControllerEvaluationStat
  :super ros::object
  :slots (_samples _last_error _average_error ))

(defmethod air_lab1::ControllerEvaluationStat
  (:init
   (&key
    ((:samples __samples) 0)
    ((:last_error __last_error) 0.0)
    ((:average_error __average_error) 0.0)
    )
   (send-super :init)
   (setq _samples (round __samples))
   (setq _last_error (float __last_error))
   (setq _average_error (float __average_error))
   self)
  (:samples
   (&optional __samples)
   (if __samples (setq _samples __samples)) _samples)
  (:last_error
   (&optional __last_error)
   (if __last_error (setq _last_error __last_error)) _last_error)
  (:average_error
   (&optional __average_error)
   (if __average_error (setq _average_error __average_error)) _average_error)
  (:serialization-length
   ()
   (+
    ;; int32 _samples
    4
    ;; float64 _last_error
    8
    ;; float64 _average_error
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _samples
       (write-long _samples s)
     ;; float64 _last_error
       (sys::poke _last_error (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _average_error
       (sys::poke _average_error (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _samples
     (setq _samples (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _last_error
     (setq _last_error (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _average_error
     (setq _average_error (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get air_lab1::ControllerEvaluationStat :md5sum-) "46c88f67df59b89f4eac2f8df597d291")
(setf (get air_lab1::ControllerEvaluationStat :datatype-) "air_lab1/ControllerEvaluationStat")
(setf (get air_lab1::ControllerEvaluationStat :definition-)
      "int32 samples           # Number of samples used for computing the error
float64 last_error      # Last error
float64 average_error   # Average error

")



(provide :air_lab1/ControllerEvaluationStat "46c88f67df59b89f4eac2f8df597d291")


